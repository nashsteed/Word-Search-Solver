CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2 -Wall# Enable all warnings
DEBUG=-g

OBJECTS = wordPuzzle.o hashTable.o timer.o

tree: $(OBJECTS)
		$(CXX) $(DEBUG) $(OBJECTS)

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h
