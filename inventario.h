#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include <vector>

class Inventario {
    std::vector<Item> items;

public:
    Inventario();
    void mostrar();
    Item obtenerItem();
};

#endif
