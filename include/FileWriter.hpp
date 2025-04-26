#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Animal.hpp"
#include "Map.hpp"

using namespace std;

class FileWriter {
    private:
        string filename;
        ofstream file;
    public:
        FileWriter(string filename);
        void addAnimalInfo(Animal animal);
        void addIteration(int i, Map map);
        void addFinalIteration(int i);
        void addAnimalIteration(Animal animal, Map map);
        void addAnimalStartingPosition(Animal animal, Map map);
        void close();
};