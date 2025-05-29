#include "item.h"

Item::Item(const std::string& nombre, TipoItem tipo, int bonusAtk, int bonusDef, int bonusLck, int curacion)
    : nombre(nombre), tipo(tipo), bonusAtk(bonusAtk), bonusDef(bonusDef), bonusLck(bonusLck), curacion(curacion) {}

std::string Item::getNombre() const { return nombre; }
TipoItem Item::getTipo() const { return tipo; }
int Item::getBonusAtk() const { return bonusAtk; }
int Item::getBonusDef() const { return bonusDef; }
int Item::getBonusLck() const { return bonusLck; }
int Item::getCuracion() const { return curacion; }
