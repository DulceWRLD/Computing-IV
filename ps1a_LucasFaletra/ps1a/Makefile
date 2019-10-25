CPP = g++ -Wall -Werror -ansi -pedantic
BOOST = -lboost_unit_test_framework
all: ps1a

ps1a: LFSR.o test.o
	$(CPP) -o ps1a LFSR.o test.o $(BOOST)

LFSR.o: LFSR.hpp LFSR.cpp
	$(CPP) -c LFSR.hpp LFSR.cpp
test.o: test.cpp
	$(CPP) -c test.cpp

clean:
	rm LFSR.o test.o ps1a LFSR.hpp.gch
