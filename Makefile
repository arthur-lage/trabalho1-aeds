CXXFLAGS = -std=c++17 -Wall -Wextra

all: somador

somador: main.o soma.o
	g++ -o somador main.o soma.o

main.o: main.cpp soma.hpp
	g++ -o main.o main.cpp -c $(CXXFLAGS)

soma.o: soma.cpp soma.hpp
	g++ -o soma.o soma.cpp -c $(CXXFLAGS)

clean:
	rm -rf *.o *~ somador