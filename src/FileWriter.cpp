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
    file << "Número de passos: " << to_string(animal.getSteps()) << endl;
    file << "Achou água " << to_string(animal.getTimesFoundWater()) << " vezes." << endl;
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

void FileWriter::addAnimalIteration(Animal animal, Map map) {
    file << "Posição do animal: "  << endl;
    file << "Passos: " << animal.getSteps() << endl;
    
    for (size_t i = 0; i < map.getForest().size(); i++)
    {
        for (size_t j = 0; j < map.getForest()[0].size(); j++)
        {
            if (static_cast<int>(i) == animal.getX() && static_cast<int>(j) == animal.getY())
            {
                file << "X ";
                continue;
            }

            file << map.getForest()[i][j] << " ";
        }

        file << endl;
    }

    file << "\n\n";
}

void FileWriter::addAnimalStartingPosition(Animal animal, Map map) {
    file << "Iniciando simulação. O animal é representado pelo X: "  << endl;
    
    for (size_t i = 0; i < map.getForest().size(); i++)
    {
        for (size_t j = 0; j < map.getForest()[0].size(); j++)
        {
            if (static_cast<int>(i) == animal.getX() && static_cast<int>(j) == animal.getY())
            {
                file << "X ";
                continue;
            }

            file << map.getForest()[i][j] << " ";
        }

        file << endl;
    }

    file << "\n\n";
}