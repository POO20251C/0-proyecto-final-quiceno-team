#include <iostream>
#include <vector>
#include "heroe.h"
#include "enemigo.h"
#include "sala.h"

int main() {
    std::vector<Heroe> heroes = {
        Heroe("Guerrero", 70, 12, 6, 5),
        Heroe("Mago", 50, 15, 3, 10),
        Heroe("Curandero", 60, 8, 5, 8)
    };

    Enemigo enemigo("Orco", 60, 10, 4, 5, TipoEnemigo::NORMAL);
    Sala sala(enemigo);

    int idx;
    do {
        std::cout << "Selecciona un héroe para pelear:\n";
        for (size_t i = 0; i < heroes.size(); i++) {
            std::cout << i+1 << ". ";
            heroes[i].mostrarInfo();
        }
        std::cin >> idx;
        idx--;
    } while (idx < 0 || idx >= (int)heroes.size() || !heroes[idx].estaVivo());

    bool victoria = sala.iniciarCombate(heroes[idx]);

    if (victoria) std::cout << "¡Has ganado la batalla!\n";
    else std::cout << "Has perdido...\n";

    return 0;
}
