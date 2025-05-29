#include "enemigo.h"

Enemigo::Enemigo(const std::string& nombre, int vida, int ataque, int defensa, int suerte, TipoEnemigo tipo)
    : Personaje(nombre, vida, ataque, defensa, suerte), tipo(tipo) {}

TipoEnemigo Enemigo::getTipo() const {
    return tipo;
}

void Enemigo::mostrarInfo() const {
    std::cout << nombre << " (Vida: " << getVida() << "/" << vidaMaxima << ")\n";
}
