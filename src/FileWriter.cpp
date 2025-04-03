#include "FileWriter.hpp"
#include "Map.hpp"

#include <iostream>
#include <vector>

using namespace std;

FileWriter::FileWriter(string filename)
{
    this->filename = filename;
    this->file = ofstream(filename);
}

void FileWriter::generateOutput() {}

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