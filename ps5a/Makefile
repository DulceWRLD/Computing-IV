C++ = g++ -O3 -std=c++11
BOOST = -lboost_unit_test_framework

all: ps5a

ps5a: RingBuffer.o test.o
	$(C++) -o ps5a RingBuffer.o test.o $(BOOST)

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(C++) -c RingBuffer.hpp RingBuffer.cpp

test.o: RingBuffer.hpp test.cpp
	$(C++) -c RingBuffer.hpp test.cpp

clean:
	rm *o *~ *.gch
