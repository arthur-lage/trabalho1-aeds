#include "FileReader.hpp"
#include "Map.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

FileReader::FileReader(string filename) {
    this->filename = filename;
    this->file = ifstream(filename);
}

Map FileReader::readMap() {
    string line;
    string value;

    int lines;
    int columns;
    int fireInitialX;
    int fireInitialY;

    int cont = 0;
    
    if(file) {
        getline(file, line);
        istringstream ss(line);

        while(ss >> value) {
            int int_value = stoi(value);
            if(cont == 0) lines = int_value;
            else if(cont == 1) columns = int_value;
            else if(cont == 2) fireInitialX = int_value;
            else if(cont == 3) fireInitialY = int_value;
            else break;

            cont++;
        }
    }

    vector<vector<int>> forest = vector<vector<int>>(lines, vector<int>(columns));

    string linha;

    while (getline(cin, linha)) {  // Lê cada linha da entrada
        vector<int> linhaNumeros;
        stringstream ss(linha);
        int num;

        while (ss >> num) {  // Lê os números da linha
            linhaNumeros.push_back(num);
        }

        if (!linhaNumeros.empty()) {
            forest.push_back(linhaNumeros);
        }
    }

    Map map = Map(lines, columns, fireInitialX, fireInitialY, forest);

    file.close();

    return map;
}
