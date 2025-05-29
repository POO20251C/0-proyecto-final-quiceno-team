#include "scoremanager.h"
#include <fstream>
#include <sstream>
#include <algorithm>

void ScoreManager::guardarScore(const ScoreEntry& entrada) {
    std::ofstream archivo("scores.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << entrada.alias << "," << entrada.salaMaxima << "," << entrada.saludPerdida << "," << entrada.fecha << "\n";
        archivo.close();
    }
}

std::vector<ScoreEntry> ScoreManager::cargarTopScores(int cantidad) {
    std::vector<ScoreEntry> scores;
    std::ifstream archivo("scores.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string alias, fecha;
            int salaMax, salud;
            std::getline(ss, alias, ',');
            ss >> salaMax;
            ss.ignore();
            ss >> salud;
            ss.ignore();
            std::getline(ss, fecha);
            scores.push_back({alias, salaMax, salud, fecha});
        }
        archivo.close();
    }
    std::sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
        if (a.salaMaxima != b.salaMaxima)
            return a.salaMaxima > b.salaMaxima;
        return a.saludPerdida < b.saludPerdida;
    });
    if ((int)scores.size() > cantidad)
        scores.resize(cantidad);
    return scores;
}
