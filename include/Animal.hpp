#pragma once

#include "Map.hpp"
#include <vector>

class Animal {
    private:
        int x;
        int y;
        int steps;
        int timesFoundWater;
        // LEFT, UP, DOWN, RIGHT
        vector<int> animalsVision;
        bool dead;
        bool usedSecondChance;
     
    public:
        Animal();
        Animal(int x, int y);

        void seeAround(Map map);

        int getSteps();
        int getTimesFoundWater();

        void addTimesFoundWater();
        void addStep();

        int getX();
        int getY();

        bool getDead();
        void die();

        void walk(Map& map);

        void showAnimal(Map map);

        bool isOnFire(Map map);
        void useSecondChance();
};