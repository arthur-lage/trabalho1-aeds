#include "FileWriter.hpp"
#include "Map.hpp"
#include "Animal.hpp"

#include <iostream>
#include <vector>

using namespace std;

FileWriter::FileWriter(string filename)
{
    this->filename = filename;
    this->file = ofstream(filename);
}

void FileWriter::addAnimalInfo(Animal animal) {
    file << "\n\n";
    file << "Informações do animal: \n";
    file << "Número de passos: " << to_string(animal.getTimesFoundWater()) << endl;
    file << "Achou água " << to_string(animal.getTimesFoundWater()) << " vezes." << endl;
    file << "Caminho do animal:" << endl;
}

void FileWriter::addIteration(int iteration, Map map)
{
    file << "Interação " << to_string(iteration) << ":" << endl;

    for (int i = 0; i < map.getLines(); i++)
    {
        for(int j = 0; j < map.getColumns(); j++) {
            file << map.getForest()[i][j] << " ";
        }

        file << "\n";
    }

    file << "\n";
}

void FileWriter::addFinalIteration(int i) {
    file << "A simulação parou na iteração: " << to_string(i) << endl;
}