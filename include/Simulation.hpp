#pragma once

#include <iostream>
#include <string>
#include <utility>

#include "config.hpp"

#include "FileReader.hpp"
#include "FileWriter.hpp"
#include "Animal.hpp"
#include "Map.hpp"

class Simulation {
    public:
        Simulation();
        void simulate();
};