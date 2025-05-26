#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
protected:
    std::string nombre;
    int hp, atk, def, spd, lck;

public:
    Personaje(std::string nombre, int hp, int atk, int def, int spd, int lck);
    virtual ~Personaje() = default;

    virtual void atacar(Personaje& objetivo);
    virtual void recibirDanio(int danio);
    virtual int calcularDanio() const;
    virtual bool estaVivo() const;

    int getVelocidad() const;
    int getSuerte() const;
    int getHP() const;
    int getDEF() const;
    std::string getNombre() const;
};

#endif // PERSONAJE_H
#ifndef PERSONAJE_H

#endif

