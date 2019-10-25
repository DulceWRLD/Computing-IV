CPP = g++ -Wall -Werror -ansi -pedantic
SFML = -lsfml-graphics -lsfml-window -lsfml-system
all: PhotoMagic

PhotoMagic: LFSR.o PhotoMagic.o
	$(CPP) -o PhotoMagic LFSR.o PhotoMagic.o $(SFML)

LFSR.o: LFSR.hpp LFSR.cpp
	$(CPP) -c LFSR.hpp LFSR.cpp
PhotoMagic.o: PhotoMagic.cpp
	$(CPP) -c PhotoMagic.cpp

clean:
	rm LFSR.o PhotoMagic.o PhotoMagic LFSR.hpp.gch
