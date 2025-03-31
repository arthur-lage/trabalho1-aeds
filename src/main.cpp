#include <iostream>
#include <string>

#include "FileReader.hpp"

int main () {
    FileReader fr = FileReader("input.dat");
    Map map = fr.readMap();

    map.show();
}