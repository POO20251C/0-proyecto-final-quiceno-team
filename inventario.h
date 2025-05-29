#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "item.h"
#include "heroe.h"

class Inventario {
private:
    std::vector<Item> items;

public:
    Inventario();
    void agregarItem(const Item& item);
    void mostrarItems() const;
    bool usarItem(int indice, Heroe& heroe);
    bool estaVacio() const;
};

#endif

