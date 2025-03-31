#pragma once

#include <iostream>
#include <vector>

class Map {
    private:
        int lines;
        int columns;
        int fireInitialX;
        int fireInitialY;
        vector<vector<int>> forest;
    public:
        Map(int l, int c, int fx, int fy, vector<vector<int>> forest);
        int getLines();
        int getColumns();
        int getFireInitialX();
        int getFireInitialY();
        vector<vector<int>> getForest();
        void show();
};