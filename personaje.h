#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
protected:
    std::string nombre;
    int vida;
    int vidaMaxima;
    int ataque;
    int defensa;
    int suerte;

public:
    Personaje(const std::string& nombre, int vida, int ataque, int defensa, int suerte);
    virtual ~Personaje() = default;

    virtual void recibirDanio(int danio);
    virtual int atacar() const;

    bool estaVivo() const;
    int getVida() const;
    int getVidaMaxima() const;
    int getAtaque() const;
    int getDefensa() const;
    int getSuerte() const;
    std::string getNombre() const;
    void curar(int puntos);

    void aumentarAtaque(int valor);
    void aumentarDefensa(int valor);
    void aumentarSuerte(int valor);
};

#endif






