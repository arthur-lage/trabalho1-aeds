#include "Animal.hpp"
#include "Map.hpp"

#include <cstdlib>
#include <ctime>

#include "config.hpp"

Animal::Animal(int x, int y)
{
    this->x = x;
    this->y = y;
    this->steps = 0;
    this->dead = false;
    this->animalsVision = {-1, -1, -1, -1};
    this->timesFoundWater = 0;
    this->usedSecondChance = false;
}

Animal::Animal()
{
    this->steps = 0;
    this->dead = false;
    this->animalsVision = {-1, -1, -1, -1};
    this->timesFoundWater = 0;
    this->usedSecondChance = false;
}

void Animal::useSecondChance() {
    this->usedSecondChance = true;
}

bool Animal::isOnFire(Map map) {
    if(map.getForest()[x][y] == 2) {
        return true;
    }

    return false;
}

void Animal::seeAround(Map map)
{
    auto forest = map.getForest();

    for (int i = 0; i < 4; i++)
    {
        int newX = x + DIRS[i].first;
        int newY = y + DIRS[i].second;

        if (newX >= 0 && newX < static_cast<int>(forest.size()) && newY >= 0 && newY < static_cast<int>(forest[0].size()))
        {
            animalsVision[i] = forest[newX][newY];
        }
        else
        {
            animalsVision[i] = -1;
        }
    }

    cout << "(" << x << "," << y << ")" << endl;
    cout << "LEFT:" << animalsVision[0] << endl;
    cout << "CIMA:" << animalsVision[1] << endl;
    cout << "DOWN:" << animalsVision[2] << endl;
    cout << "RIGHT:" << animalsVision[3] << endl;
}

void Animal::addTimesFoundWater()
{
    this->timesFoundWater += 1;
}

void Animal::addStep()
{
    this->steps += 1;
}

int Animal::getTimesFoundWater()
{
    return this->timesFoundWater;
}

int Animal::getSteps()
{
    return this->steps;
}

int Animal::getX()
{
    return this->x;
}

int Animal::getY()
{
    return this->y;
}

bool Animal::getDead()
{
    return this->dead;
}

void Animal::die()
{
    this->dead = true;
}

void Animal::walk(Map& map)
{
    auto alreadyTested = map.getAlreadyTested();
    auto forest = map.getForest();

        // LEFT, UP, DOWN, RIGHT

    vector<pair<pair<int, int>, int>> possibleSteps;

    for (int i = 0; i < 4; i++)
    {

        // cout  << "olhando agora: " << i << " - " << animalsVision[i] << endl;
        if (animalsVision[i] == -1)
        {
            continue;
        }

        int currentCell = animalsVision[i];
        int newX = x + DIRS[i].first;
        int newY = y + DIRS[i].second;

        if (alreadyTested[newX][newY])
        {
            continue;
        }

        if (currentCell == 4)
        {
            possibleSteps.clear();
            possibleSteps.push_back({{newX, newY}, 4});
            break;
        }
        else if (currentCell == 0 || currentCell == 1)
        {
            possibleSteps.push_back({{newX, newY}, 1});
        }
        else if (currentCell == 3)
        {
            possibleSteps.push_back({{newX, newY}, 3});
        }
    }

    if (possibleSteps.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            if (animalsVision[i] == -1)
            {
                continue;
            }

            int currentCell = animalsVision[i];
            int newX = x + DIRS[i].first;
            int newY = y + DIRS[i].second;

            if (currentCell == 4)
            {
                possibleSteps.clear();
                possibleSteps.push_back({{newX, newY}, 4});
                break;
            }
            else if (currentCell == 0 || currentCell == 1)
            {
                possibleSteps.push_back({{newX, newY}, 1});
            }
            else if (currentCell == 3)
            {
                possibleSteps.push_back({{newX, newY}, 3});
            }
        }
    }

    if (!possibleSteps.empty())
    {
        int bestValue = possibleSteps[0].second;
        for (const auto &step : possibleSteps)
        {
            if (step.second > bestValue)
            {
                bestValue = step.second;
            }
        }

        vector<pair<int, int>> bestSteps;
        for (const auto &step : possibleSteps)
        {
            if (step.second == bestValue)
            {
                bestSteps.push_back(step.first);
            }
        }

        srand(time(nullptr));
        int randomIndex = rand() % bestSteps.size();
        pair<int, int> bestNextStep = bestSteps[randomIndex];

        x = bestNextStep.first;
        y = bestNextStep.second;

        // cout << "melhor opcao: " << forest[bestNextStep.first][bestNextStep.second];

        map.addToAlreadyTested(bestNextStep.first, bestNextStep.second);
        addStep();
    }
}

void Animal::showAnimal(Map map)
{
    cout << "Animal X: " << x << endl;
    cout << "Animal Y: " << y << endl;
    cout << "Steps: " << steps << endl;
    cout << "Times Found water: " << timesFoundWater << endl;

    cout << "Matriz lida:\n";

    for (size_t i = 0; i < map.getForest().size(); i++)
    {
        for (size_t j = 0; j < map.getForest()[0].size(); j++)
        {
            if (static_cast<int>(i) == x && static_cast<int>(j) == y)
            {
                cout << "X ";
                continue;
            }

            cout << map.getForest()[i][j] << " ";
        }

        cout << endl;
    }
}