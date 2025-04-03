#include "Animal.hpp"


Animal::Animal() {
    this->steps = 0;
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