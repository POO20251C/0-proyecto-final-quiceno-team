#include "personaje.h"
#include <cstdlib>

Personaje::Personaje(const std::string& nombre, int vida, int ataque, int defensa)
    : nombre(nombre), vida(vida), ataque(ataque), defensa(defensa) {}

void Personaje::recibirDanio(int danio) {
    int danioReal = danio - defensa;
    if (danioReal < 1) danioReal = 1;
    vida -= danioReal;
    if (vida < 0) vida = 0;
}

int Personaje::atacar() const {
    return ataque;
}

bool Personaje::estaVivo() const {
    return vida > 0;
}

std::string Personaje::getNombre() const {
    return nombre;
}
