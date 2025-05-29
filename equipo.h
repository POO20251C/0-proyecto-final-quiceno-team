#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
private:
    int bonusHP, bonusATK, bonusDEF, bonusLCK;
    std::string nombre;
public:
    Equipo(std::string n, int hp, int atk, int def, int lck);
    int getBonusHP() const;
    int getBonusATK() const;
    int getBonusDEF() const;
    int getBonusLCK() const;
    std::string getNombre() const;
};

#endif
