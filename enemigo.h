#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"
#include <iostream>

enum class TipoEnemigo {
    NORMAL,
    MINIJEFE,
    JEFEFINAL
};

class Enemigo : public Personaje {
private:
    TipoEnemigo tipo;

public:
    Enemigo(const std::string& nombre, int vida, int ataque, int defensa, int suerte, TipoEnemigo tipo);
    TipoEnemigo getTipo() const;
    void mostrarInfo() const;
};

#endif
