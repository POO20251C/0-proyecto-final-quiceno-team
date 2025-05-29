#include "sala.h"
#include <iostream>

Sala::Sala(const Enemigo& enemigo) : enemigo(enemigo) {}

bool Sala::iniciarCombate(Heroe& heroe) {
    while (heroe.estaVivo() && enemigo.estaVivo()) {
        std::cout << "\n1. Atacar\n2. Usar poción (" << heroe.getPociones() << " disponibles)\n";
        int opcion;
        std::cin >> opcion;

        if (opcion == 1) {
            int danio = heroe.atacar();
            enemigo.recibirDanio(danio);
            std::cout << heroe.getNombre() << " inflige " << danio << " daño.\n";
        } else if (opcion == 2) {
            if (!heroe.usarPocion()) {
                std::cout << "No tienes pociones.\n";
            } else {
                std::cout << heroe.getNombre() << " usa una poción y recupera vida.\n";
            }
        } else {
            std::cout << "Opción inválida.\n";
            continue;
        }

        if (enemigo.estaVivo()) {
            int danio = enemigo.atacar();
            std::cout << enemigo.getNombre() << " contraataca con " << danio << " daño.\n";
            heroe.recibirDanio(danio);
        }
    }
    return heroe.estaVivo();
}
