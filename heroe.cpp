#include "Heroe.h"
#include <iostream>

Heroe::Heroe(std::string nombre)
    : Personaje(nombre, 60, 6, 3, 4, 1), hpMax(60) {}

void Heroe::subirStats() {
    atk += static_cast<int>(atk * 0.02);
    def += static_cast<int>(def * 0.02);
}

void Heroe::curar(int cantidad) {
    hp += cantidad;
    if (hp > hpMax) hp = hpMax;
}

void Heroe::equipar(const Equipo& eq) {
    equipo = eq;
    hpMax += eq.getBonusHP();
    atk += eq.getBonusATK();
    def += eq.getBonusDEF();
    lck += eq.getBonusLCK();

    std::cout << nombre << " equipado: +HP " << eq.getBonusHP()
              << ", +ATK " << eq.getBonusATK()
              << ", +DEF " << eq.getBonusDEF()
              << ", +LCK " << eq.getBonusLCK() << "\n";
}

int Heroe::getHPMax() const {
    return hpMax;
}


