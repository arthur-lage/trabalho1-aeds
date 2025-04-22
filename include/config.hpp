#pragma once

#include <vector>
#include <iostream>
#include <utility>

// Opções: UP, DOWN, LEFT, RIGHT
// Deixar vazio para espalhar o fogo em todas as direções
// Exemplo - Espalhar o fogo em direções específicas (UP, DOWN, LEFT, RIGHT): 
//
//     std::vector<std::string> DIRECTIONS_WIND = {"UP", "DOWN"};
//
extern std::vector<std::string> DIRECTIONS_WIND;


// Quantidade máxima de iterações na simulação
extern int ITERATIONS;

extern std::vector<std::pair<int,int>> DIRS;
