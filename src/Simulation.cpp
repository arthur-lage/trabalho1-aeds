#include <iostream>

#include "Simulation.hpp"

Simulation::Simulation () {}

void Simulation::simulate () {
    int final_iteration = 1;
    FileReader fr = FileReader("input.dat");
    FileWriter fw = FileWriter("output.dat");

    Map map = fr.readMap();
    pair<int, int> animalPos = map.getAnimalRandomPosition();

    if(map.getFireInitialX() == animalPos.first && map.getFireInitialY() == animalPos.second) {
        cout << "Impossível fazer simulação. O animal iniciou o percurso sendo pego pelo fogo. Escolha outra posição para o fogo." << endl;
        return;
    }

    Animal animal(animalPos.first, animalPos.second);

    fw.addAnimalStartingPosition(animal, map);

    animal.showAnimal(map);

    map.markInitialAnimalPosition(animal.getX(), animal.getY());

    for(int i = 1; i < ITERATIONS + 1; i++) {
        if(!map.shouldContinueSimulation()) {
            break;
        }

        if(animal.getDead()) {
            cout << "Morreu." << endl;
            break;
        }

        if (animal.isOnFire(map)) {
            animal.useSecondChance();
            map.goToLastIteration();
            continue;
        }

        animal.seeAround(map);
        animal.walk(map);
        
        map.iterate();

        if(map.getForest()[animal.getX()][animal.getY()] == 4) {
            map.foundWater(animal.getX(), animal.getY());
            animal.addTimesFoundWater();
        }
        
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

    cout << "A simulação foi encerrada agora." << endl;

    fw.addFinalIteration(final_iteration);
    fw.addAnimalInfo(animal);
}