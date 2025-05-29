#include <iostream>
#include "heroe.h"
#include "enemigo.h"
#include "sala.h"

int main() {
    Heroe heroe("Héroe Básico", 50, 10, 5);
    Enemigo enemigo("Enemigo Básico", 40, 8, 3);
    Sala sala(enemigo);

    bool victoria = sala.iniciarCombate(heroe);

    if (victoria) std::cout << "¡Ganaste!\n";
    else std::cout << "Perdiste...\n";

    return 0;
}
