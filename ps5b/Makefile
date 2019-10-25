C++ = g++ -std=c++11
SFML = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: GuitarHero

GuitarHero: GuitarString.o GuitarHero.o RingBuffer.o RingBuffer.o
	$(C++) -o GuitarHero GuitarString.o RingBuffer.o GuitarHero.o  $(SFML)

GuitarHero.o: GuitarHero.cpp GuitarString.hpp RingBuffer.hpp GuitarString.cpp RingBuffer.cpp
	$(C++) -c GuitarHero.cpp GuitarString.hpp RingBuffer.hpp GuitarString.cpp RingBuffer.cpp


GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.hpp RingBuffer.cpp
	$(C++) -c GuitarString.cpp RingBuffer.cpp GuitarString.hpp RingBuffer.hpp

clean:
	rm GuitarHero *.o *~ *.gch
