#include "Sala.h"
#include <iostream>
#include <algorithm>

Sala::Sala(Enemigo e) : enemigo(e) {}

bool Sala::iniciarBatalla(std::vector<Heroe>& heroes) {
    std::cout << "Comienza la batalla contra " << enemigo.getNombre() << "!\n";

    while (enemigo.estaVivo() && heroes[0].estaVivo()) {
        std::sort(heroes.begin(), heroes.end(),
                  [](Heroe& a, Heroe& b) { return a.getVelocidad() > b.getVelocidad(); });

        for (auto& heroe : heroes) {
            if (heroe.estaVivo() && enemigo.estaVivo()) {
                heroe.atacar(enemigo);
            }
        }

        if (enemigo.estaVivo()) {
            enemigo.atacar(heroes[0]);
        }
    }

    if (!enemigo.estaVivo()) {
        std::cout << "¡Victoria!\n";
        for (auto& h : heroes) h.subirStats();
        return true;
    } else {
        std::cout << "Derrota...\n";
        return false;
    }
}
