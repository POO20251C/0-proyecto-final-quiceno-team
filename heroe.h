#ifndef HEROE_H
#define HEROE_H

#include "personaje.h"
#include "enums.h"
#include <iostream>

class Heroe : public Personaje {
private:
    Rol rol;
    int pociones;

public:
    Heroe(const std::string& nombre, int vida, int ataque, int defensa, int suerte, Rol rol);

    Rol getRol() const;
    void mostrarInfo() const;

    void agregarPociones(int cantidad);
    bool usarPocion();
    int getPociones() const;
};

#endif






