#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

class Enemigo : public Personaje {
public:
    Enemigo(const std::string& nombre, int vida, int ataque, int defensa);
};

#endif
