#include "Enemigo.h"

Enemigo::Enemigo(std::string nombre, TipoEnemigo tipo)
    : Personaje(nombre,
                tipo == GRAN_JEFE ? 120 : tipo == MINI_JEFE ? 90 : 60,
                tipo == GRAN_JEFE ? 15 : tipo == MINI_JEFE ? 10 : 6,
                tipo == GRAN_JEFE ? 10 : tipo == MINI_JEFE ? 6 : 3,
                tipo == GRAN_JEFE ? 6 : tipo == MINI_JEFE ? 4 : 2,
                tipo == GRAN_JEFE ? 5 : tipo == MINI_JEFE ? 3 : 1),
      tipo(tipo) {}

TipoEnemigo Enemigo::getTipo() const {
    return tipo;
}

