#include "sala.h"
#include <iostream>

Sala::Sala(const Enemigo& enemigo) : enemigo(enemigo) {}

bool Sala::iniciarCombate(Heroe& heroe) {
    while (heroe.estaVivo() && enemigo.estaVivo()) {
        int danioHeroe = heroe.atacar();
        enemigo.recibirDanio(danioHeroe);
        if (!enemigo.estaVivo()) break;

        int danioEnemigo = enemigo.atacar();
        heroe.recibirDanio(danioEnemigo);
    }
    return heroe.estaVivo();
}
