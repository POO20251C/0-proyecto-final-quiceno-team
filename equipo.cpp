#include "Equipo.h"
#include <iostream>

Equipo::Equipo(std::string nombre, int hp, int atk, int def, int lck)
    : nombre(nombre), bonusHP(hp), bonusATK(atk), bonusDEF(def), bonusLCK(lck) {}

std::string Equipo::getNombre() const {
    return nombre;
}

int Equipo::getBonusHP() const {
    return bonusHP;
}

int Equipo::getBonusATK() const {
    return bonusATK;
}

int Equipo::getBonusDEF() const {
    return bonusDEF;
}

int Equipo::getBonusLCK() const {
    return bonusLCK;
}

void Equipo::mostrar() const {
    std::cout << nombre << " | +HP: " << bonusHP
              << " +ATK: " << bonusATK
              << " +DEF: " << bonusDEF
              << " +LCK: " << bonusLCK << "\n";
}
