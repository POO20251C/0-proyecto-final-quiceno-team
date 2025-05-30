#include "heroe.h"

Heroe::Heroe(const std::string& nombre, int vida, int ataque, int defensa, int suerte, Rol rol)
    : Personaje(nombre, vida, ataque, defensa, suerte), rol(rol), pociones(0) {}

Rol Heroe::getRol() const {
    return rol;
}

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
    std::cout << ", Vida: " << vida << "/" << vidaMaxima << ", ATK: " << ataque << ", DEF: " << defensa << ", LCK: " << suerte
              << ", Pociones: " << pociones << ")\n";
}

void Heroe::agregarPociones(int cantidad) {
    pociones += cantidad;
}

bool Heroe::usarPocion() {
    if (pociones > 0) {
        curar(30);  // Cada poción cura 30 HP
        pociones--;
        std::cout << getNombre() << " usa una poción y recupera 30 puntos de vida.\n";
        return true;
    }
    std::cout << getNombre() << " no tiene pociones para usar.\n";
    return false;
}

int Heroe::getPociones() const {
    return pociones;
}

