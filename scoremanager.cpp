#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <ctime>

void ScoreManager::guardarScore(const std::string& jugador, int sala, int saludPerdida) {
    std::ofstream file("scores.txt", std::ios::app);
    time_t now = time(nullptr);
    file << jugador << " " << sala << " " << saludPerdida << " " << ctime(&now);
    file.close();
}

void ScoreManager::mostrarTopScores() {
    std::ifstream file("scores.txt");
    std::string line;
    std::cout << "=== TOP SCORES ===\n";
    int count = 0;
    while (std::getline(file, line) && count < 5) {
        std::cout << line << "\n";
        count++;
    }
}

