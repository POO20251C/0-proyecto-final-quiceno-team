#ifndef HEROE_H
#define HEROE_H

#include "personaje.h"
#include <iostream>

class Heroe : public Personaje {
private:
    int pociones;

public:
    Heroe(const std::string& nombre, int vida, int ataque, int defensa, int suerte);

    bool usarPocion();
    void agregarPociones(int cantidad);
    int getPociones() const;
    void mostrarInfo() const;
};

#endif
