#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>
#include <vector>

struct ScoreEntry {
    std::string alias;
    int salaMaxima;
    int saludPerdida;
    std::string fecha;
};

class ScoreManager {
public:
    static void guardarScore(const ScoreEntry& entrada);
    static std::vector<ScoreEntry> cargarTopScores(int cantidad = 5);
};

#endif
