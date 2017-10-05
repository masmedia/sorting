# Locations of gcc and g++ compilers are assigned to CC and CXX variables
CC=/usr/bin/gcc
CXX=/usr/bin/g++

# To create an output file with .o extension, the dependecy is a .cpp file
build: main.cpp
	$(CXX) -o main main.cpp

# To run the compiled file, the dependency is .out file
run: main.out
	./main
