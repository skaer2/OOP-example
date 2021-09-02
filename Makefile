CXX=g++
CC=g++
CXXFLAGS=-g -Wall -MMD -std=c++11
LDLIBS=-lm -lfreeglut -lglew32 -lopengl32 -lglu32 
all: main.o GraphicsComponent.o ShapesComponent.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
clean:
	rm -f *.o
