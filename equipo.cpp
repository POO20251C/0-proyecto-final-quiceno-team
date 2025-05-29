#include "Equipo.h"

Equipo::Equipo(std::string n, int hp, int atk, int def, int lck)
    : nombre(n), bonusHP(hp), bonusATK(atk), bonusDEF(def), bonusLCK(lck) {}

int Equipo::getBonusHP() const { return bonusHP; }
int Equipo::getBonusATK() const { return bonusATK; }
int Equipo::getBonusDEF() const { return bonusDEF; }
int Equipo::getBonusLCK() const { return bonusLCK; }
std::string Equipo::getNombre() const { return nombre; }
