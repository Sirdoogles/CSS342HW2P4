
# print out each command being executed 
all: test.x

MyMatrix.o: MyMatrix.cpp
	g++ -Wall -c MyMatrix.cpp -o MyMatrix.o

test.o: test.cpp
	g++ -Wall -c test.cpp -o test.o

test.x: test.o MyMatrix.o
	g++ test.o MyMatrix.o -o test.x

clean:
	rm -rf *o all