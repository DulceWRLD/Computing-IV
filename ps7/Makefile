C++ = g++ -std=c++14 -O3
BOOST = -lboost_regex -lboost_date_time

all: PS7

PS7: main.o
	$(C++) -o PS7 main.o $(BOOST)

stdin_boost.o:	main.cpp
	$(C++) -c main.cpp

clean:
	rm *~ *.o PS7
