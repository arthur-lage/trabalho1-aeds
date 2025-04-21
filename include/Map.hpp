#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Map
{
private:
    int lines;
    int columns;
    int fireInitialX;
    int fireInitialY;
    vector<vector<int>> forest;
    vector<vector<int>> lastIteration;
    vector<vector<bool>> alreadyTested;

public:
    Map(int l, int c, int fx, int fy, vector<vector<int>> forest);
    int getLines();
    int getColumns();
    int getFireInitialX();
    int getFireInitialY();
    vector<vector<int>> getForest();

    void spreadFire();
    void show();
    void iterate();

    bool shouldContinueSimulation();

    pair<int, int> getAnimalRandomPosition();

    void foundWater(int x, int y);
    vector<vector<bool>> getAlreadyTested();
    void markInitialAnimalPosition (int x, int y);

    void goToLastIteration();

    void addToAlreadyTested (int x, int y);
    void showAlreadyTested();
};