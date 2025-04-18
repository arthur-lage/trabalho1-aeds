#pragma once

#include "Map.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileReader {
    private:
        string filename;
        ifstream file;
    public:
        FileReader(string filename);
        Map readMap();
};