#include "Heroe.h"
#include "Enemigo.h"
#include "Sala.h"
#include "Inventario.h"
#include "ScoreManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void mostrarHeroes(const std::vector<Heroe>& heroes) {
    for (size_t i = 0; i < heroes.size(); ++i) {
        std::cout << i + 1 << ". " << heroes[i].getNombre()
                  << " | HP: " << heroes[i].getHP() << "\n";
    }
}

int elegirHeroe(const std::vector<Heroe>& heroes) {
    int eleccion = 0;
    do {
        std::cout << "Elige un héroe por número: ";
        std::cin >> eleccion;
    } while (eleccion < 1 || eleccion > heroes.size());
    return eleccion - 1;
}

void usarCofre(std::vector<Heroe>& equipo) {
    std::cout << "Has encontrado un cofre:\n1. Amuleto (+2 LCK)\n2. 3 Pociones\nElige: ";
    int eleccion;
    std::cin >> eleccion;

    if (eleccion == 1) {
        int idx = elegirHeroe(equipo);
        std::cout << "Equipaste el amuleto a " << equipo[idx].getNombre() << " (+2 LCK)\n";
        equipo[idx].subirStats(); // Simular efecto
    } else {
        for (int i = 0; i < 3; ++i) {
            std::cout << "Elige héroe para poción " << i + 1 << ": \n";
            int idx = elegirHeroe(equipo);
            std::cout << "Curando a " << equipo[idx].getNombre() << " (+10 HP)\n";
            equipo[idx].curar(10);
        }
    }
}

void combateInteractivo(Heroe& heroe, Enemigo& enemigo) {
    while (heroe.estaVivo() && enemigo.estaVivo()) {
        std::cout << "\nTurno de " << heroe.getNombre() << " | HP: " << heroe.getHP()
                  << "/" << heroe.getHPMax() << "\n";
        std::cout << "1. Atacar\n2. Pasar turno\nTu acción: ";
        int accion;
        std::cin >> accion;

        if (accion == 1) {
            int danio = heroe.calcularDanio() - enemigo.getDEF();
            if (danio < 1) danio = 1;
            enemigo.recibirDanio(danio);
            std::cout << heroe.getNombre() << " inflige " << danio << " a " << enemigo.getNombre() << "\n";
        }

        if (enemigo.estaVivo()) {
            int danio = enemigo.calcularDanio() - heroe.getDEF();
            if (danio < 1) danio = 1;
            heroe.recibirDanio(danio);
            std::cout << enemigo.getNombre() << " inflige " << danio << " a " << heroe.getNombre() << "\n";
        }
    }

    if (!enemigo.estaVivo())
        std::cout << enemigo.getNombre() << " fue derrotado.\n";
    else
        std::cout << heroe.getNombre() << " ha caído.\n";
}

void eventoSalaEspecial(std::vector<Heroe>& equipo, int sala) {
    if (sala == 1) {
        std::cout << "\n=== Mercado Inicial ===\n";
        Equipo arma = {0, 5, 0, 1}; // +5 ATK, +1 LCK
        int idx = elegirHeroe(equipo);
        equipo[idx].equipar(arma);
    }
    else if (sala == 3) {
        std::cout << "\n=== Cofre Misterioso ===\n";
        usarCofre(equipo); // ya lo tenías implementado
    }
    else if (sala == 6) {
        std::cout << "\n=== Tesoro Raro ===\n";
        for (auto& h : equipo) {
            Equipo recompensa = {0, 8, 0, 2}; // +8 ATK, +2 LCK
            h.equipar(recompensa);
        }
    }
    else if (sala == 8) {
        std::cout << "\n=== Santo Grial ===\n";
        for (auto& h : equipo) h.curar(999);
        std::cout << "¡Todos los héroes se han curado por completo!\n";
    }
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::string jugador;
    std::cout << "=== Natal Combat ===\n";
    std::cout << "Ingresa tu alias: ";
    std::getline(std::cin, jugador);

    std::vector<Heroe> pool = {
        Heroe("Ayla"), Heroe("Tyr"), Heroe("Kira"),
        Heroe("Nash"), Heroe("Luna"), Heroe("Zorak")
    };

    std::vector<Heroe> equipo;

    std::cout << "Selecciona 3 héroes:\n";
    mostrarHeroes(pool);

    while (equipo.size() < 3) {
        int idx = elegirHeroe(pool);
        equipo.push_back(pool[idx]);
        pool.erase(pool.begin() + idx);
    }

    // Mazmorra
    std::vector<Enemigo> enemigos = {
        Enemigo("Goblin", SOLDADO),
        Enemigo("Orco", SOLDADO),
        Enemigo("Liche", SOLDADO),
        Enemigo("Nigromante", SOLDADO),
        Enemigo("Ogro", SOLDADO),
        Enemigo("Gólem", SOLDADO),
        Enemigo("Caballero Negro", MINI_JEFE),
        Enemigo("Demonio", SOLDADO),
        Enemigo("Señor Oscuro", GRAN_JEFE)
    };

    int salaActual = 0;
    int saludPerdida = 0;

    for (size_t i = 0; i < enemigos.size(); ++i) {
        std::cout << "\n-- Sala " << i + 1 << " --\n";

        // Eventos especiales
        if (i == 2) usarCofre(equipo);
        if (i == 6) {
            std::cout << "¡Has encontrado el Santo Grial! Todos tus héroes recuperan salud.\n";
            for (auto& h : equipo) h.curar(999);
        }

        std::cout << "Te enfrentas a: " << enemigos[i].getNombre() << "\n";

        for (auto& h : equipo) {
            if (enemigos[i].estaVivo() && h.estaVivo()) {
                combateInteractivo(h, enemigos[i]);
            }
        }

        if (enemigos[i].estaVivo()) {
            std::cout << "No pudiste superar esta sala. Fin del juego.\n";
            break;
        }

        salaActual++;
    }

    for (auto& h : equipo)
        saludPerdida += 60 - h.getHP();

    ScoreManager::guardarScore(jugador, salaActual, saludPerdida);
    std::cout << "\nPuntaje registrado. Tus estadísticas:\n";
    ScoreManager::mostrarTopScores();

    return 0;
}
