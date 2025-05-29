#include "sala.h"
#include <iostream>
#include <limits>
#include <cstdlib>

Sala::Sala(const Enemigo& enemigo) : enemigo(enemigo) {}

bool Sala::iniciarCombate(Heroe& heroe) {
    std::cout << "\nSe enfrenta " << heroe.getNombre() << " contra ";
    enemigo.mostrarInfo();

    while (heroe.estaVivo() && enemigo.estaVivo()) {
        std::cout << "\nElige una acción:\n";
        std::cout << "1. Atacar\n";
        std::cout << "2. Usar poción (" << heroe.getPociones() << " disponibles)\n";
        std::cout << "3. Curar (+10 HP)\n";

        int opcion;
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcion == 1) {
            int danio = heroe.atacar();
            std::cout << heroe.getNombre() << " ataca e inflige " << danio << " de daño.\n";
            enemigo.recibirDanio(danio);
        } else if (opcion == 2) {
            if (!heroe.usarPocion()) {
                std::cout << "No tienes pociones. Pierdes el turno.\n";
            }
        } else if (opcion == 3) {
            std::cout << heroe.getNombre() << " se cura 10 puntos de vida.\n";
            heroe.curar(10);
        } else {
            std::cout << "Acción inválida.\n";
            continue;
        }

        if (enemigo.estaVivo()) {
            int danio = enemigo.atacar();

            switch (enemigo.getTipo()) {
                case TipoEnemigo::NORMAL:
                    break;
                case TipoEnemigo::MINIJEFE:
                    std::cout << "¡" << enemigo.getNombre() << " usa Furia! +5 de daño.\n";
                    danio += 5;
                    break;
                case TipoEnemigo::JEFEFINAL:
                    if (rand() % 100 < 25) {
                        std::cout << "¡" << enemigo.getNombre() << " usa Megaataque! Doble daño.\n";
                        danio *= 2;
                    }
                    break;
            }

            std::cout << enemigo.getNombre() << " contraataca e inflige " << danio << " de daño.\n";
            heroe.recibirDanio(danio);
        }
    }

    return heroe.estaVivo();
}
