#pragma once

class Animal {
    private:
        int steps;
        int timesFoundWater;

    public:
        int getSteps();
        int getTimesFoundWater();

        void addTimesFoundWater();
        void addStep();
};