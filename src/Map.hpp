#pragma once

#include <iostream>

class Map {
    private:
        int lines;
        int columns;
        int fireInitialX;
        int fireInitialY;
    public:
        Map(int l, int c, int fx, int fy);
        int getLines();
        int getColumns();
        int getFireInitialX();
        int getFireInitialY();
        void show();
};