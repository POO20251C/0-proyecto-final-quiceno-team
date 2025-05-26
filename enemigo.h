#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

enum TipoEnemigo { SOLDADO, MINI_JEFE, GRAN_JEFE };

class Enemigo : public Personaje {
    TipoEnemigo tipo;

public:
    Enemigo(std::string nombre, TipoEnemigo tipo);
    TipoEnemigo getTipo() const;
};

#endif
