#include "config.hpp"

// Opções: UP, DOWN, LEFT, RIGHT
// Deixar vazio para espalhar o fogo em todas as direções
// Exemplo - Espalhar o fogo em direções específicas (UP, DOWN, LEFT, RIGHT): 
//
//     std::vector<std::string> DIRECTIONS_WIND = {"UP", "DOWN"};
//

std::vector<std::string> DIRECTIONS_WIND = {};


// Número máximo de iterações usadas na simulação:
//

int ITERATIONS = 50;

// Vetor de direções possiveis

std::vector<std::pair<int,int>> DIRS = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
