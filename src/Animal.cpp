#include "Animal.hpp"
#include "Map.hpp"

#include "config.hpp"

Animal::Animal(int x, int y) {
    this->x = x;
    this->y = y;
    this->steps = 0;
    this->dead = false;
    this->animalsVision = {-1, -1, -1, -1};
    this->timesFoundWater = 0;
}

Animal::Animal() {
    this->steps = 0;
    this->dead = false;
    this->animalsVision = {-1, -1, -1, -1};
    this->timesFoundWater = 0;
}

void Animal::seeAround(Map map) {
    auto forest = map.getForest();

    for(int i = 0; i < 4; i++) {
        int newX = x + DIRS[i].first;
        int newY = y + DIRS[i].second;

        if(newX >= 0 && newX < static_cast<int>(forest.size()) && newY >= 0 && newY < static_cast<int>(forest[0].size())) {
            animalsVision[i] = forest[newX][newY];
        } else {
            animalsVision[i] = -1;
        }
    }
}

void Animal::addTimesFoundWater() {
    this->timesFoundWater += 1;
}

void Animal::addStep() {
    this->steps += 1;
}

int Animal::getTimesFoundWater() {
    return this->timesFoundWater;
}

int Animal::getSteps() {
    return this->steps;
}

int Animal::getX() {
    return this->x;
}

int Animal::getY() {
    return this->y;
}

bool Animal::getDead() {
    return this->dead;
}

void Animal::die() {
    this->dead = true;
}

void Animal::walk(Map map) {
    auto forest = map.getForest();
    pair<int, int> bestNextStep = {-1, -1};
    int bestOption = -1;

    for(int i = 0; i < 4; i++) {
        if(animalsVision[i] == -1) {
            continue;
        }

        int currentCell = animalsVision[i];
        int newX = x + DIRS[i].first;
        int newY = y + DIRS[i].second;

        if(currentCell == 4) {
            bestNextStep = {newX, newY};
            bestOption = 4;
            break;
        }
        else if(currentCell == 0 || currentCell == 1) {
            if(bestOption < 1) {
                bestOption = 1;
                bestNextStep = {newX, newY};
            }
        }
        else if(currentCell == 3 && bestOption == -1) {
            bestOption = 3;
            bestNextStep = {newX, newY};
        }
    }

    if(bestNextStep.first != -1 && bestNextStep.second != -1) {
        x = bestNextStep.first;
        y = bestNextStep.second;
        addStep();
    }
}

void Animal::showAnimal(Map map) {
    cout << "Animal X: " << x << endl;
    cout << "Animal Y: " << y << endl;
    cout << "Steps: " << steps << endl;
    cout << "Times Found water: " << timesFoundWater << endl;

    cout << "Matriz lida:\n";

    for (size_t i = 0; i < map.getForest().size(); i++) 
    {
        for (size_t j = 0; j < map.getForest()[0].size(); j++) 
        {
            if (static_cast<int>(i) == x && static_cast<int>(j) == y) {
                cout << "X ";
                continue;
            }

            cout << map.getForest()[i][j] << " ";
        }
        
        cout << endl;
    }
}