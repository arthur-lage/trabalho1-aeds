#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Map {
    private:
        int lines;
        int columns;
        int fireInitialX;
        int fireInitialY;
        vector<vector<int>> forest;
        vector<vector<int>> forestMod;
    public:
        Map(int l, int c, int fx, int fy, vector<vector<int>> forest);
        int getLines();
        int getColumns();
        int getFireInitialX();
        int getFireInitialY();
        vector<vector<int>> getForest();
        vector<vector<int>> getForestMod();

        void burn(int x, int y);
        void spreadFire();
        void show();
        void iterate();
};