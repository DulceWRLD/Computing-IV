CPP = g++ -O3 -Wall -Werror -std=c++14
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: NBody

NBody: main.o Body.o
	$(CPP) -o NBody main.o Body.o $(SFML)
main.o: main.cpp
	$(CPP) -c main.cpp

Body.o: Body.hpp Body.cpp
	$(CPP) -c Body.hpp Body.cpp
clean:
	rm *~ *.o NBody Body.hpp.gch
