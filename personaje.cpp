#include "Personaje.h"
#include <iostream>
#include <cstdlib>

Personaje::Personaje(std::string nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void Personaje::atacar(Personaje& objetivo) {
    int danio = calcularDanio() - objetivo.getDEF();
    if (danio < 1) danio = 1;
    objetivo.recibirDanio(danio);
    std::cout << nombre << " infligió " << danio << " de daño a " << objetivo.getNombre() << ".\n";
}

int Personaje::calcularDanio() const {
    int base = atk + (rand() % 5); // Variación de 0 a 4
    bool critico = (rand() % 100) < (lck * 2);
    if (critico) {
        std::cout << "¡Golpe crítico de " << nombre << "!\n";
        return base * 2;
    }
    return base;
}

void Personaje::recibirDanio(int danio) {
    hp -= danio;
    if (hp < 0) hp = 0;
}

bool Personaje::estaVivo() const { return hp > 0; }

int Personaje::getVelocidad() const { return spd; }
int Personaje::getSuerte() const { return lck; }
int Personaje::getHP() const { return hp; }
int Personaje::getDEF() const { return def; }
std::string Personaje::getNombre() const { return nombre; }

