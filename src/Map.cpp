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
    this->alreadyTested = vector<vector<bool>>(lines, vector<bool>(columns, false));
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

    for (string dir : DIRECTIONS_WIND) {
        if (dir == "UP") direcoes.push_back(0);
        else if (dir == "DOWN") direcoes.push_back(1);
        else if (dir == "LEFT") direcoes.push_back(2);
        else if (dir == "RIGHT") direcoes.push_back(3);
    }
    return direcoes;
}

bool Map::shouldContinueSimulation() {
    for (size_t i = 0; i < forest.size(); i++) {
        for (size_t j = 0; j < forest[i].size(); j++) {
            if (forest[i][j] == 1) { // Árvore saudável
                // Verifica vizinhança (4 direções)
                if ((i > 0 && forest[i-1][j] == 2) ||                   // UP
                    (i < forest.size()-1 && forest[i+1][j] == 2) ||   // DOWN
                    (j > 0 && forest[i][j-1] == 2) ||                   // LEFT
                    (j < forest[i].size()-1 && forest[i][j+1] == 2)) { // RIGHT
                    return true; // Há árvores que podem pegar fogo
                }
            }
            else if (forest[i][j] == 2) {
                return true; // Ainda há árvores em chamas
            }
        }
    }
    return false;
}

void Map::spreadFire()
{
    if (lines == 0 || columns == 0) return;
    
    vector<vector<bool>> willBurn(lines, vector<bool>(columns, false));
    
    vector<int> direcoes = convertDirections();
    bool comVento = !DIRECTIONS_WIND.empty();

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (forest[i][j] == 1) {
                for (int d = 0; d < 4; d++) {
                    if (comVento && find(direcoes.begin(), direcoes.end(), d) == direcoes.end()) {
                        continue;
                    }
                    
                    int ni = i, nj = j;
                    switch(d) {
                        case 0: ni--; break;
                        case 1: ni++; break;
                        case 2: nj--; break;
                        case 3: nj++; break;
                    }
                    
                    if (ni >= 0 && ni < lines && nj >= 0 && nj < columns && forest[ni][nj] == 2) {
                        willBurn[i][j] = true;
                        break; 
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (forest[i][j] == 2) {
                forest[i][j] = 3;
            } else if (willBurn[i][j]) {
                forest[i][j] = 2;
            }
        }
    }
}

vector<vector<bool>> Map::getAlreadyTested() {
    return this->alreadyTested;
}

void Map::iterate()
{
    spreadFire();
}

pair<int, int> Map::getAnimalRandomPosition() {
    pair<int, int> pos = {-1, -1};
    bool found = false;
    
    for(size_t i = 0; i < forest.size(); i++) {
        if(found) break;

        for(size_t j = 0; j < forest[0].size(); j++) {
            if(forest[i][j] == 0) {
                pos.first = i;
                pos.second = j;
                found = true;
            }

            if(found) break;
        }
    }

    if(pos.first == -1 || pos.second == -1) {
        cout << "Não existem posições disponíveis para o animal iniciar a simulação." << endl;
        exit(1);
    }

    return pos;
}

void Map::foundWater (int x, int y) {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    forest[x][y] = 0;
        
    for(int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(newX >= 0 && newX < static_cast<int>(forest.size()) && newY >= 0 && newY < static_cast<int>(forest[0].size())) {
            forest[newX][newY] = 1;
        }
    }
}