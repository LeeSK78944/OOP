.SUFFIXES: .cpp .o

OBJECTS = human.o shared_ref.o smart_obj.o student.o weak_pointer.o

TEST = test.o $(OBJECTS)

CXX = g++

TARGET = test

$(TARGET) : $(TEST)
			  $(CXX) -o $(TARGET) $(TEST)

clean:
	rm -rf $(TEST) $(TARGET)

test.o : test.cpp
human.o : human.cpp
shared_ref.o : shared_ref.cpp
smart_obj.o : smart_obj.cpp
student.o : student.cpp
weak_pointer.o : weak_pointer.cpp
