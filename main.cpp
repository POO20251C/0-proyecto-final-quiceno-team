#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <limits>
#include <cstdlib>

#include "heroe.h"
#include "enemigo.h"
#include "sala.h"
#include "item.h"
#include "inventario.h"
#include "enums.h"
#include "ScoreManager.h" // Nuevo encabezado para puntuaciones

struct Score {
    std::string alias;
    int maxSala;
    int saludPerdida;
    std::string fecha;

    bool operator<(const Score& other) const {
        if (maxSala != other.maxSala)
            return maxSala > other.maxSala;
        return saludPerdida < other.saludPerdida;
    }
};

void mostrarTopScores() {
    auto scores = ScoreManager::cargarTopScores();
    std::cout << "Top 5 mejores puntuaciones:\n";
    for (size_t i = 0; i < scores.size(); i++) {
        std::cout << i+1 << ". " << scores[i].alias << " - Sala: " << scores[i].salaMaxima << " - Salud perdida: " << scores[i].saludPerdida << " - Fecha: " << scores[i].fecha << "\n";
    }
}

// Eventos de salas especiales
void eventoMercadoInicial(std::vector<Heroe>& heroes) {
    std::cout << "\n*** Mercado Inicial ***\n";
    std::cout << "Compra arma y armadura común para tus héroes.\n";

    Item armaComun("Espada Común", TipoItem::ARMA, 5, 0, 0);
    Item armaduraComun("Armadura Común", TipoItem::ARMADURA, 0, 5, 0);

    std::cout << "Elige héroe para arma común:\n";
    for (size_t i = 0; i < heroes.size(); i++) {
        std::cout << i+1 << ". " << heroes[i].getNombre() << "\n";
    }
    int idx;
    std::cin >> idx; idx--;

    heroes[idx].aumentarAtaque(armaComun.getBonusAtk());

    std::cout << "Elige héroe para armadura común:\n";
    std::cin >> idx; idx--;
    heroes[idx].aumentarDefensa(armaduraComun.getBonusDef());

    std::cout << "Mercado finalizado.\n";
}

void eventoCofre(std::vector<Heroe>& heroes) {
    std::cout << "\n*** Cofre (Sala 3) ***\n";
    std::cout << "Elige: 1) Accesorio de Suerte (+2 LCK) o 2) 3 pociones de curación para héroes.\n";
    int eleccion;
    std::cin >> eleccion;

    if (eleccion == 1) {
        Item accesorio("Amuleto de Suerte", TipoItem::ARMADURA, 0, 0, 2);
        std::cout << "Elige héroe para amuleto:\n";
        for (size_t i = 0; i < heroes.size(); i++) {
            std::cout << i+1 << ". " << heroes[i].getNombre() << "\n";
        }
        int idx;
        std::cin >> idx; idx--;
        heroes[idx].aumentarSuerte(accesorio.getBonusLck());
    } else if (eleccion == 2) {
        std::cout << "3 pociones de curación para héroes (curan 20 HP).\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << "Elige héroe para pocion #" << i+1 << ":\n";
            for (size_t j = 0; j < heroes.size(); j++) {
                std::cout << j+1 << ". " << heroes[j].getNombre() << "\n";
            }
            int idx;
            std::cin >> idx; idx--;
            heroes[idx].curar(20);
        }
    } else {
        std::cout << "Elección inválida.\n";
    }
}

void eventoTesoro(std::vector<Heroe>& heroes) {
    std::cout << "\n*** Tesoro (Sala 6) ***\n";
    std::cout << "Has obtenido tres armas raras: +8 ATK y +5% LCK para cada héroe.\n";
    for (auto& h : heroes) {
        h.aumentarAtaque(8);
        h.aumentarSuerte(5);
    }
}

void eventoSantoGrial(std::vector<Heroe>& heroes) {
    std::cout << "\n*** Santo Grial (Sala 8) ***\n";
    std::cout << "Todos los héroes recuperan el 100% de su salud.\n";
    for (auto& h : heroes) {
        h.curar(h.getVidaMaxima());
    }
}

int main() {
    srand((unsigned)time(NULL));

    std::cout << "===== BIENVENIDO A LA MAZMORRA =====\n";

    mostrarTopScores();

    std::string jugador;
    std::cout << "Ingresa tu alias: ";
    std::getline(std::cin, jugador);

    std::vector<Heroe> heroes = {
        Heroe("Jon Snow", 80, 35, 45, 10, Rol::GUERRERO),
        Heroe("Daenerys", 80, 40, 30, 20, Rol::MAGO),
        Heroe("Ygritte", 70, 30, 12, 25, Rol::ARQUERO),
        Heroe("Hodor", 65, 18, 40, 35, Rol::CURANDERO),
        Heroe("Sabueso", 500, 50, 70, 15, Rol::TANQUE),
        Heroe("Arya", 150, 15, 40, 50, Rol::LADRON)
    };

    std::vector<Sala> mazmorra = {
        Sala(Enemigo("Joffrey envenedado", 60, 15, 10, 5, TipoEnemigo::NORMAL)),
        Sala(Enemigo("Domen sin cabeza", 70, 18, 12, 5, TipoEnemigo::NORMAL)),
        Sala(Enemigo("Littlefinger degollado", 100, 35, 15, 7, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Robb Wolfhead", 120, 50, 13, 6, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Ramsay", 100, 35, 16, 8, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Bronn borracho", 60, 35, 18, 10, TipoEnemigo::NORMAL)),
        Sala(Enemigo("Tyrion zombie", 110, 50, 20, 12, TipoEnemigo::MINIJEFE)),
        Sala(Enemigo("Tywin Oscuro", 140, 55, 22, 15, TipoEnemigo::JEFEFINAL)),
        Sala(Enemigo("Montaña zombie", 150, 60, 25, 20, TipoEnemigo::JEFEFINAL)),
        Sala(Enemigo("Rey de la noche", 200, 65, 30, 25, TipoEnemigo::JEFEFINAL))
    };

    int salaActual = 0;
    int muertes = 0;
    int saludPerdidaAcumulada = 0;

    while (salaActual < (int)mazmorra.size() && muertes < 2) {
        std::cout << "\n--- Sala " << salaActual + 1 << " ---\n";

        if (salaActual == 0) eventoMercadoInicial(heroes);
        else if (salaActual == 2) eventoCofre(heroes);
        else if (salaActual == 5) eventoTesoro(heroes);
        else if (salaActual == 7) eventoSantoGrial(heroes);

        int heroeSeleccionado = -1;
        do {
            std::cout << "Selecciona un héroe para pelear:\n";
            for (size_t i = 0; i < heroes.size(); i++) {
                std::cout << i + 1 << ". " << heroes[i].getNombre() << " (HP: " << heroes[i].getVida() << "/" << heroes[i].getVidaMaxima() << ")\n";
            }
            std::cin >> heroeSeleccionado;
            heroeSeleccionado--;
        } while (heroeSeleccionado < 0 || heroeSeleccionado >= (int)heroes.size() || !heroes[heroeSeleccionado].estaVivo());

        bool victoria = mazmorra[salaActual].iniciarCombate(heroes[heroeSeleccionado]);
        if (!victoria) {
            muertes++;
            std::cout << "Has perdido un héroe.\n";
        }

        int saludAntes = 0;
        int saludDespues = 0;
        for (auto& h : heroes) {
            saludAntes += h.getVidaMaxima();
            saludDespues += h.getVida();
        }
        saludPerdidaAcumulada = saludAntes - saludDespues;

        if (victoria) {
            for (auto& h : heroes) {
                int atkInc = h.getAtaque() * 0.02;
                int defInc = h.getDefensa() * 0.02;
                h.aumentarAtaque(atkInc > 0 ? atkInc : 1);
                h.aumentarDefensa(defInc > 0 ? defInc : 1);
            }
        }

        salaActual++;
    }

    if (muertes >= 2) {
        std::cout << "\nGAME OVER. Has perdido 2 héroes.\n";
    } else {
        std::cout << "\n¡Felicidades! Has completado la mazmorra.\n";
    }

    time_t now = time(0);
    tm* now_tm = localtime(&now);
    char fecha[20];
    strftime(fecha, sizeof(fecha), "%Y-%m-%d", now_tm);

    ScoreEntry entrada = { jugador, salaActual, saludPerdidaAcumulada, fecha };
    ScoreManager::guardarScore(entrada);

    std::cout << "Gracias por jugar, " << jugador << "!\n";

    return 0;
}



