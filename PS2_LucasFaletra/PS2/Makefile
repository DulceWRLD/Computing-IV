CPP = g++ -O3 -Wall -Werror -pedantic
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: tree

tree: main.o Ptree.o
	$(CPP) -o tree main.o Ptree.o $(SFML)
main.o: main.cpp
	$(CPP) -c main.cpp

Ptree.o: Ptree.hpp Ptree.cpp
	$(CPP) -c Ptree.hpp Ptree.cpp
clean:
	rm *~ *.o tree Ptree.hpp.gch
