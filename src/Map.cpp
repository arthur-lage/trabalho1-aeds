#include "Map.hpp"

#include "config.hpp"

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

Map::Map(int l, int c, int fx, int fy, vector<vector<int>> forest)
{
    this->lines = l;
    this->columns = c;
    this->fireInitialX = fx;
    this->fireInitialY = fy;
    this->forest = forest;
}

int Map::getLines() { return this->lines; }
int Map::getColumns() { return this->columns; }
int Map::getFireInitialX() { return this->fireInitialX; }
int Map::getFireInitialY() { return this->fireInitialY; }

vector<vector<int>> Map::getForest()
{
    return forest;
}

void Map::show()
{
    cout << "Lines: " << lines << endl;
    cout << "Columns: " << columns << endl;
    cout << "Fire Init X: " << fireInitialX << endl;
    cout << "Fire Init Y: " << fireInitialY << endl;

    cout << "Matriz lida:\n";

    for (const auto &row : forest)
    {
        for (int num : row)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

vector<int> convertDirections() {
    vector<int> direcoes;

    for (string dir : DIRECTIONS) {
        if (dir == "UP") direcoes.push_back(0);
        else if (dir == "DOWN") direcoes.push_back(1);
        else if (dir == "LEFT") direcoes.push_back(2);
        else if (dir == "RIGHT") direcoes.push_back(3);
    }
    return direcoes;
}

void Map::spreadFire()
{
    if (lines == 0 || columns == 0) return;
    
    vector<vector<bool>> willBurn(lines, vector<bool>(columns, false));
    
    vector<int> direcoes = convertDirections();
    bool comVento = !DIRECTIONS.empty();

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (forest[i][j] == 1) { // Árvore saudável
                // Verifica todas as 4 direções
                for (int d = 0; d < 4; d++) {
                    // Se há vento configurado E a direção não está na lista, pula
                    if (comVento && find(direcoes.begin(), direcoes.end(), d) == direcoes.end()) {
                        continue;
                    }
                    
                    // Calcula nova posição
                    int ni = i, nj = j;
                    switch(d) {
                        case 0: ni--; break; // UP
                        case 1: ni++; break; // DOWN
                        case 2: nj--; break; // LEFT
                        case 3: nj++; break; // RIGHT
                    }
                    
                    // Verifica se está dentro dos limites e se há fogo
                    if (ni >= 0 && ni < lines && nj >= 0 && nj < columns && forest[ni][nj] == 2) {
                        willBurn[i][j] = true;
                        break; // Basta um vizinho em chamas
                    }
                }
            }
        }
    }
    
    // Atualizar o estado da floresta
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (forest[i][j] == 2) {
                forest[i][j] = 3; // Árvore queimada
            } else if (willBurn[i][j]) {
                forest[i][j] = 2; // Árvore pega fogo
            }
        }
    }
}

void Map::iterate()
{
    this->spreadFire();
}