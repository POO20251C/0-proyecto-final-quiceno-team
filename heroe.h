#ifndef HEROE_H
#define HEROE_H

#include "personaje.h"

class Heroe : public Personaje {
public:
    Heroe(const std::string& nombre, int vida, int ataque, int defensa);
};

#endif
