#include <iostream>
#include <vector>
#include <ctime>
#include "heroe.h"
#include "enemigo.h"
#include "sala.h"
#include "item.h"
#include "inventario.h"
#include "enums.h"
#include "scoremanager.h"

void eventoMercadoInicial(std::vector<Heroe>& heroes, Inventario& inventario) {
    std::cout << "\n*** Mercado Inicial ***\n";
    Item arma("Espada Común", TipoItem::ARMA, 5, 0, 0);
    Item armadura("Armadura Común", TipoItem::ARMADURA, 0, 5, 0);
    inventario.agregarItem(arma);
    inventario.agregarItem(armadura);
    std::cout << "Compra completada, items añadidos al inventario.\n";
}

void eventoCofre(std::vector<Heroe>& heroes, Inventario& inventario) {
    std::cout << "\n*** Cofre (Sala 3) ***\n";
    inventario.agregarItem(Item("Poción", TipoItem::POCION, 0, 0, 0, 20));
    inventario.agregarItem(Item("Poción", TipoItem::POCION, 0, 0, 0, 20));
    inventario.agregarItem(Item("Poción", TipoItem::POCION, 0, 0, 0, 20));
    std::cout << "3 pociones añadidas al inventario.\n";
}

void eventoTesoro(std::vector<Heroe>& heroes) {
    std::cout << "\n*** Tesoro (Sala 6) ***\n";
    for (auto& h : heroes) {
        h.aumentarAtaque(8);
        h.aumentarSuerte(5);
    }
    std::cout << "Todos los héroes aumentan ataque y suerte.\n";
}

void eventoSantoGrial(std::vector<Heroe>& heroes) {
    std::cout << "\n*** Santo Grial (Sala 8) ***\n";
    for (auto& h : heroes) {
        h.curar(h.getVidaMaxima());
    }
    std::cout << "Todos los héroes recuperan la salud completa.\n";
}

int main() {
    srand((unsigned)time(NULL));
    std::vector<Heroe> heroes = {
        Heroe("Jon Snow", 80, 35, 45, 10, Rol::GUERRERO),
        Heroe("Daenerys", 80, 40, 30, 20, Rol::MAGO),
        Heroe("Ygritte", 70, 30, 12, 25, Rol::ARQUERO),
        Heroe("Hodor", 65, 18, 40, 35, Rol::CURANDERO),
        Heroe("Sabueso", 500, 50, 70, 15, Rol::TANQUE),
        Heroe("Arya", 150, 15, 40, 50, Rol::LADRON)
    };

    std::vector<Sala> mazmorra = {
        Sala(Enemigo("Joffrey", 60, 15, 10, 5, TipoEnemigo::NORMAL)),
        Sala(Enemigo("Robb Wolfhead", 120, 50, 13, 6, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Ramsay", 100, 35, 16, 8, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Bronn", 60, 35, 18, 10, TipoEnemigo::NORMAL)),
        Sala(Enemigo("Tyrion", 110, 50, 20, 12, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Tywin Oscuro", 140, 55, 22, 15, TipoEnemigo::JEFEFINAL)),
        Sala(Enemigo("Montaña", 150, 60, 25, 20, TipoEnemigo::JEFEFINAL)),
        Sala(Enemigo("Rey de la noche", 200, 65, 30, 25, TipoEnemigo::JEFEFINAL))
    };

    Inventario inventario;
    int salaActual = 0;
    int muertes = 0;

    while (salaActual < (int)mazmorra.size() && muertes < 2) {
        if (salaActual == 0) eventoMercadoInicial(heroes, inventario);
        else if (salaActual == 2) eventoCofre(heroes, inventario);
        else if (salaActual == 5) eventoTesoro(heroes);
        else if (salaActual == 7) eventoSantoGrial(heroes);

        std::cout << "\nSala " << salaActual + 1 << "\n";

        int heroeSeleccionado = -1;
        do {
            std::cout << "Selecciona un héroe para pelear:\n";
            for (size_t i = 0; i < heroes.size(); i++) {
                heroes[i].mostrarInfo();
            }
            std::cin >> heroeSeleccionado;
            heroeSeleccionado--;
        } while (heroeSeleccionado < 0 || heroeSeleccionado >= (int)heroes.size() || !heroes[heroeSeleccionado].estaVivo());

        bool victoria = mazmorra[salaActual].iniciarCombate(heroes[heroeSeleccionado]);

        if (!victoria) {
            muertes++;
            std::cout << "Has perdido un héroe.\n";
        } else {
            for (auto& h : heroes) {
                int atkInc = h.getAtaque() * 0.02;
                int defInc = h.getDefensa() * 0.02;
                h.aumentarAtaque(atkInc > 0 ? atkInc : 1);
                h.aumentarDefensa(defInc > 0 ? defInc : 1);
            }
            std::cout << "Victoria en sala " << salaActual + 1 << "!\n";
        }

        salaActual++;
    }

    if (muertes >= 2) std::cout << "\nGAME OVER. Has perdido 2 héroes.\n";
    else std::cout << "\n¡Felicidades! Has completado la mazmorra.\n";

    return 0;
}
