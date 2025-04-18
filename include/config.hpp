#pragma once

#include <vector>
#include <iostream>
#include <utility>

// Opções: UP, DOWN, LEFT, RIGHT
// Deixar vazio para espalhar o fogo em todas as direções
// Para espalhar o fogo em direções específicas: vector<string> DIRECTIONS = {"UP", "DOWN"};
extern std::vector<std::string> DIRECTIONS_WIND;

extern int ITERATIONS;

extern std::vector<std::pair<int,int>> DIRS;
