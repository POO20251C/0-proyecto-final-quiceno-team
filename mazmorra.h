#ifndef MAZMORRA_H
#define MAZMORRA_H

#include "Heroe.h"
#include "Sala.h"
#include <vector>

class Mazmorra {
    std::vector<Heroe> heroes;
    std::vector<Sala> salas;

public:
    Mazmorra(const std::vector<Heroe>& heroes);
    void iniciar();
};

#endif
