#include "Mazmorra.h"
#include "ScoreManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Mazmorra::Mazmorra(const std::vector<Heroe>& heroes)
    : heroes(heroes) {
    salas = {
        Sala(Enemigo("Goblin", SOLDADO)),
        Sala(Enemigo("Orco", SOLDADO)),
        Sala(Enemigo("Esqueleto", SOLDADO)),
        Sala(Enemigo("Liche", SOLDADO)),
        Sala(Enemigo("Nigromante", SOLDADO)),
        Sala(Enemigo("Ogro", SOLDADO)),
        Sala(Enemigo("Gólem", SOLDADO)),
        Sala(Enemigo("Caballero Negro", MINI_JEFE)),
        Sala(Enemigo("Demonio", SOLDADO)),
        Sala(Enemigo("Señor Oscuro", GRAN_JEFE))
    };
}

void Mazmorra::iniciar() {
    std::string jugador;
    std::cout << "Ingresa tu alias: ";
    std::getline(std::cin, jugador);

    int salaActual = 0;
    int saludPerdida = 0;

    for (auto& sala : salas) {
        if (sala.iniciarBatalla(heroes)) {
            salaActual++;
        } else {
            break;
        }
    }

    for (auto& h : heroes)
        saludPerdida += 60 - h.getHP();

    ScoreManager::guardarScore(jugador, salaActual, saludPerdida);
    ScoreManager::mostrarTopScores();
}
