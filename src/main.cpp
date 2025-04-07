#include <iostream>
#include <string>

#include "config.hpp"

#include "FileReader.hpp"
#include "FileWriter.hpp"
#include "Animal.hpp"

int main () {
    int final_iteration = 1;
    FileReader fr = FileReader("input.dat");
    FileWriter fw = FileWriter("output.dat");

    Animal animal;

    Map map = fr.readMap();

    for(int i = 1; i < ITERATIONS + 1; i++) {
        if(!map.deveContinuarSimulacao()) {
            break;
        }
        
        map.iterate();
        
        cout << "Iteração " << to_string(i) << ":" << endl;
        map.show();

        // add iteration to output file
        fw.addIteration(i, map);
        final_iteration = i;
    }

    fw.addFinalIteration(final_iteration);
    fw.addAnimalInfo(animal);
}