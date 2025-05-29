#include "enemigo.h"

Enemigo::Enemigo(const std::string& nombre, int vida, int ataque, int defensa, int suerte, TipoEnemigo tipo)
    : Personaje(nombre, vida, ataque, defensa, suerte), tipo(tipo) {}

TipoEnemigo Enemigo::getTipo() const {
    return tipo;
}

void Enemigo::mostrarInfo() const {
    std::cout << nombre << " (Tipo: ";
    switch (tipo) {
        case TipoEnemigo::NORMAL: std::cout << "Normal"; break;
        case TipoEnemigo::MINIJEFE: std::cout << "Mini Jefe"; break;
        case TipoEnemigo::JEFEFINAL: std::cout << "Jefe Final"; break;
    }
    std::cout << ", Vida: " << vida << "/" << vidaMaxima << ", ATK: " << ataque << ", DEF: " << defensa << ", LCK: " << suerte << ")\n";
}

