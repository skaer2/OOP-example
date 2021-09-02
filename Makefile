CXX=g++
CC=g++
CXXFLAGS=-g -Wall -MMD -std=c++11
LDLIBS=-lm -lfreeglut -lglew32 -lopengl32 -lglu32 -lmuparser
all: testtask
clean:
	rm -f *.o testtask
