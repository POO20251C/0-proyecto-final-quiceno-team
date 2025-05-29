#ifndef SALA_H
#define SALA_H

#include "heroe.h"
#include "enemigo.h"

class Sala {
private:
    Enemigo enemigo;

public:
    Sala(const Enemigo& enemigo);
    bool iniciarCombate(Heroe& heroe);
};

#endif


