#include <iostream>
#include <string>

#include "config.hpp"

#include "FileReader.hpp"
#include "FileWriter.hpp"

int main () {
    FileReader fr = FileReader("input.dat");
    FileWriter fw = FileWriter("output.dat");

    Map map = fr.readMap();

    for(int i = 0; i < ITERATIONS; i++) {
        map.iterate();

        // add iteration to output file
        fw.addIteration(i + 1, map);
    }
}