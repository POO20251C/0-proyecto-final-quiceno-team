#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "enums.h"

class Item {
private:
    std::string nombre;
    TipoItem tipo;
    int bonusAtk;
    int bonusDef;
    int bonusLck;
    int curacion;

public:
    Item(const std::string& nombre, TipoItem tipo, int bonusAtk = 0, int bonusDef = 0, int bonusLck = 0, int curacion = 0);

    std::string getNombre() const;
    TipoItem getTipo() const;
    int getBonusAtk() const;
    int getBonusDef() const;
    int getBonusLck() const;
    int getCuracion() const;
};

#endif
