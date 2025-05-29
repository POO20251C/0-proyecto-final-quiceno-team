#include "personaje.h"
#include <cstdlib>
#include <iostream>

Personaje::Personaje(const std::string& nombre, int vida, int ataque, int defensa, int suerte)
    : nombre(nombre), vida(vida), vidaMaxima(vida), ataque(ataque), defensa(defensa), suerte(suerte) {}

void Personaje::recibirDanio(int danio) {
    int danioReal = danio - defensa;
    if (danioReal < 1) danioReal = 1;
    vida -= danioReal;
    if (vida < 0) vida = 0;
    std::cout << nombre << " recibe " << danioReal << " de daño, vida restante: " << vida << "\n";
}

int Personaje::atacar() const {
    int base = ataque + (rand() % 5);
    int critChance = suerte * 2;
    bool critico = (rand() % 100) < critChance;
    if (critico) {
        std::cout << "¡Golpe crítico de " << nombre << "!\n";
        return base * 2;
    }
    return base;
}

bool Personaje::estaVivo() const {
    return vida > 0;
}

int Personaje::getVida() const { return vida; }
int Personaje::getVidaMaxima() const { return vidaMaxima; }
std::string Personaje::getNombre() const { return nombre; }

void Personaje::curar(int puntos) {
    vida += puntos;
    if (vida > vidaMaxima) vida = vidaMaxima;
}

void Personaje::aumentarAtaque(int valor) { ataque += valor; }
void Personaje::aumentarDefensa(int valor) { defensa += valor; }
void Personaje::aumentarSuerte(int valor) { suerte += valor; }
