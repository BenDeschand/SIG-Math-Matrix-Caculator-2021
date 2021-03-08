main: main.o matrix.o
	g++ -o main main.o matrix.o

main.o: main.cpp matrix.h
	g++ -c main.cpp

test: test.o matrix.o
	g++ -o test test.o matrix.o

test.o: test.cpp matrix.h
	g++ -c test.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

clean: 
	rm main.o test.o matrix.o main test