#include <iostream>
#include <vector>
#include "heroe.h"
#include "enemigo.h"
#include "sala.h"
#include "item.h"
#include "inventario.h"
#include "enums.h"

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

int main() {
    std::vector<Heroe> heroes = {
        Heroe("Jon Snow", 80, 35, 45, 10, Rol::GUERRERO),
        Heroe("Daenerys", 80, 40, 30, 20, Rol::MAGO),
        Heroe("Ygritte", 70, 30, 12, 25, Rol::ARQUERO)
    };

    std::vector<Sala> mazmorra = {
        Sala(Enemigo("Joffrey", 60, 15, 10, 5, TipoEnemigo::NORMAL)),
        Sala(Enemigo("Robb Wolfhead", 120, 50, 13, 6, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Tywin Oscuro", 140, 55, 22, 15, TipoEnemigo::JEFEFINAL))
    };

    Inventario inventario;
    int salaActual = 0;

    while (salaActual < (int)mazmorra.size()) {
        if (salaActual == 0) eventoMercadoInicial(heroes, inventario);
        if (salaActual == 2) eventoCofre(heroes, inventario);

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

        if (!victoria) std::cout << "Has perdido la batalla.\n";
        else std::cout << "Victoria en sala " << salaActual + 1 << "!\n";

        salaActual++;
    }

    std::cout << "Juego terminado.\n";
    return 0;
}
