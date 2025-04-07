#pragma once

class Animal {
    private:
        int x;
        int y;
        int steps;
        int timesFoundWater;

    public:
        Animal();

        int getSteps();
        int getTimesFoundWater();

        void addTimesFoundWater();
        void addStep();

        int getX();
        int getY();
};