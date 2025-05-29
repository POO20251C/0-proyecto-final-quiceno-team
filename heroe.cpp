#include "heroe.h"

Heroe::Heroe(const std::string& nombre, int vida, int ataque, int defensa, int suerte)
    : Personaje(nombre, vida, ataque, defensa, suerte), pociones(1) {}

bool Heroe::usarPocion() {
    if (pociones > 0) {
        curar(20);
        pociones--;
        return true;
    }
    return false;
}

void Heroe::agregarPociones(int cantidad) {
    pociones += cantidad;
}

int Heroe::getPociones() const {
    return pociones;
}

void Heroe::mostrarInfo() const {
    std::cout << nombre << " HP: " << getVida() << "/" << vidaMaxima << " Pociones: " << pociones << "\n";
}
