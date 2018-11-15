program: main.o rational.o matrix.o 
	g++ -o program main.o rational.o matrix.o 

main.o: main.cpp rational.h matrix.h
	g++ -c main.cpp -o main.o -std=c++11

rational.o: rational.cpp rational.h
	g++ -c rational.cpp -o rational.o -std=c++11

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp -o matrix.o -std=c++11
