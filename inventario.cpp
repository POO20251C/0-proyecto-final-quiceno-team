#include "inventario.h"
#include <iostream>

Inventario::Inventario() {}

void Inventario::agregarItem(const Item& item) {
    if (items.size() < 50) {
        items.push_back(item);
    }
}

void Inventario::mostrarItems() const {
    if (items.empty()) {
        std::cout << "Inventario vacío.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); i++) {
        const Item& it = items[i];
        std::cout << i + 1 << ". " << it.getNombre();
        if (it.getTipo() == TipoItem::POCION)
            std::cout << " (Poción, cura " << it.getCuracion() << " HP)";
        else
            std::cout << " (+" << it.getBonusAtk() << " ATK, +" << it.getBonusDef() << " DEF, +" << it.getBonusLck() << " LCK)";
        std::cout << "\n";
    }
}

bool Inventario::usarItem(int indice, Heroe& heroe) {
    if (indice < 1 || indice > (int)items.size()) return false;
    Item it = items[indice - 1];
    if (it.getTipo() == TipoItem::POCION) {
        heroe.curar(it.getCuracion());
        std::cout << heroe.getNombre() << " usa poción y cura " << it.getCuracion() << " HP.\n";
    } else {
        heroe.aumentarAtaque(it.getBonusAtk());
        heroe.aumentarDefensa(it.getBonusDef());
        heroe.aumentarSuerte(it.getBonusLck());
        std::cout << heroe.getNombre() << " equipa " << it.getNombre() << ".\n";
    }
    items.erase(items.begin() + (indice - 1));
    return true;
}

bool Inventario::estaVacio() const {
    return items.empty();
}
