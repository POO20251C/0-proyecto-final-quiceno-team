#include "Inventario.h"
#include <iostream>

Inventario::Inventario() {
    items.push_back({"Espada Básica", ARMA, 4, 0, 0});
    items.push_back({"Armadura de Cuero", ARMADURA, 0, 5, 0});
    items.push_back({"Amuleto de Suerte", ACCESORIO, 0, 0, 2});
}

void Inventario::mostrar() {
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i << ") " << items[i].nombre << "\n";
    }
}

Item Inventario::obtenerItem() {
    return items[rand() % items.size()];
}
