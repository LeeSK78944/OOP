.SUFFIXES: .cpp .o

CXX = g++

CPPFLAGS = -Wall -O

OBJECTS = main.o board.o block.o tree.o fold.o cross.o

TARGET = puyopuyoTetris

$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJECTS)
clean:
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
block.o : block.cpp
tree.o : tree.cpp
cross.o : cross.cpp
fold.o : fold.cpp
board.o : board.cpp

