#ifndef SALA_H
#define SALA_H

#include "Heroe.h"
#include "Enemigo.h"
#include <vector>

class Sala {
    Enemigo enemigo;

public:
    Sala(Enemigo e);
    bool iniciarBatalla(std::vector<Heroe>& heroes);
};

#endif
