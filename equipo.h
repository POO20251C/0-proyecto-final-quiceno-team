#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
private:
    std::string nombre;
    int bonusHP;
    int bonusATK;
    int bonusDEF;
    int bonusLCK;

public:
    Equipo(std::string nombre = "Ninguno", int hp = 0, int atk = 0, int def = 0, int lck = 0);

    std::string getNombre() const;
    int getBonusHP() const;
    int getBonusATK() const;
    int getBonusDEF() const;
    int getBonusLCK() const;

    void mostrar() const;
};

#endif
