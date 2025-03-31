#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileWriter {
    private:
        string filename;
        ofstream file;
    public:
        void generateOutput();
};