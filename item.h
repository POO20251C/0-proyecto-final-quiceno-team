#ifndef ITEM_H
#define ITEM_H

#include <string>

enum TipoItem { ARMA, ARMADURA, ACCESORIO };

struct Item {
    std::string nombre;
    TipoItem tipo;
    int bonusATK;
    int bonusDEF;
    int bonusLCK;
};

#endif

