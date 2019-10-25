C++ = g++ -std=c++14 -O3
SFML = -lsfml-system -lsfml-graphics
all: ED

ED: main.o ED.o
	$(C++) -o ED main.o ED.o $(SFML)

main.o: main.cpp
	$(C++) -c main.cpp

ED.o: ED.cpp ED.hpp
	$(C++) -c ED.cpp ED.hpp

clean:
	rm ED *.o *~ *.gch  
