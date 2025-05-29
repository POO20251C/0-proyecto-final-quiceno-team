#include "heroe.h"

Heroe::Heroe(const std::string& nombre, int vida, int ataque, int defensa, int suerte, Rol rol)
    : Personaje(nombre, vida, ataque, defensa, suerte), rol(rol), pociones(1) {}

Rol Heroe::getRol() const { return rol; }

void Heroe::mostrarInfo() const {
    std::cout << nombre << " (Rol: ";
    switch (rol) {
        case Rol::GUERRERO: std::cout << "Guerrero"; break;
        case Rol::MAGO: std::cout << "Mago"; break;
        case Rol::CURANDERO: std::cout << "Curandero"; break;
        case Rol::ARQUERO: std::cout << "Arquero"; break;
        case Rol::TANQUE: std::cout << "Tanque"; break;
        case Rol::LADRON: std::cout << "Ladrón"; break;
    }
    std::cout << ", Vida: " << getVida() << "/" << getVidaMaxima() << ", ATK: " << ataque << ", DEF: " << defensa << ", LCK: " << suerte
              << ", Pociones: " << pociones << ")\n";
}

void Heroe::agregarPociones(int cantidad) { pociones += cantidad; }

bool Heroe::usarPocion() {
    if (pociones > 0) {
        curar(30);
        pociones--;
        std::cout << nombre << " usa una poción y recupera 30 puntos de vida.\n";
        return true;
    }
    return false;
}

int Heroe::getPociones() const { return pociones; }
