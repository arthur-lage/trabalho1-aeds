#include "Map.hpp"
#include <vector>

using namespace std;

Map::Map(int l, int c, int fx, int fy, vector<vector<int>> forest) {
    this->lines = l;
    this->columns = c;
    this->fireInitialX = fx;
    this->fireInitialY = fy;
    this->forest = forest;
}

int Map::getLines() {return this->lines;}
int Map::getColumns() {return this->columns;}
int Map::getFireInitialX() {return this->fireInitialX;}
int Map::getFireInitialY() {return this->fireInitialY;}

vector<vector<int>> Map::getForest() {
    return forest;
}

void Map::show() {
    cout << "Lines: " << lines << endl;
    cout << "Columns: " << columns << endl;
    cout << "Fire Init X: " << fireInitialX << endl;
    cout << "Fire Init Y: " << fireInitialY << endl;

    cout << "Matriz lida:\n";
    for (const auto& linha : forest) {
        for (int num : linha) {
            std::cout << num << " ";
        }

        std::cout << "\n";
    }
}