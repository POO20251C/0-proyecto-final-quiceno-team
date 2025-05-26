#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
public:
    static void guardarScore(const std::string& jugador, int sala, int saludPerdida);
    static void mostrarTopScores();
};

#endif
