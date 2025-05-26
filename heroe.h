#ifndef HEROE_H
#define HEROE_H

#include "Personaje.h"
#include "Equipo.h"

class Heroe : public Personaje {
    Equipo equipo;
    int hpMax;

public:
    Heroe(std::string nombre);

    void subirStats();
    void curar(int cantidad);
    void equipar(const Equipo& eq);

    int getHPMax() const;
};

#endif


