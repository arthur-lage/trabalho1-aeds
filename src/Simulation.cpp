#include <iostream>

#include "Simulation.hpp"

Simulation::Simulation () {}

void Simulation::simulate () {
    int final_iteration = 1;
    FileReader fr = FileReader("input.dat");
    FileWriter fw = FileWriter("output.dat");

    Map map = fr.readMap();
    pair<int, int> animalPos = map.getAnimalRandomPosition();

    Animal animal(animalPos.first, animalPos.second);

    animal.showAnimal(map);

    for(int i = 1; i < ITERATIONS + 1; i++) {
        if(!map.shouldContinueSimulation()) {
            break;
        }

        if(animal.getDead()) {
            cout << "Morreu." << endl;
            break;
        }

        animal.seeAround(map);
        animal.walk(map);

        if(map.getForest()[animal.getX()][animal.getY()] == 4) {
            map.foundWater(animal.getX(), animal.getY());
            animal.addTimesFoundWater();
        }
        
        map.iterate();
        
        cout << "\n\n" << endl;

        cout << "Iteração " << to_string(i) << ":" << endl;
        map.show();

        cout << "\n\n" << endl;

        animal.showAnimal(map);

        cout << "\n\n" << endl;

        // add iteration to output file
        fw.addIteration(i, map);
        fw.addAnimalIteration(animal, map);
        final_iteration = i;
    }

    fw.addFinalIteration(final_iteration);
    fw.addAnimalInfo(animal);
}