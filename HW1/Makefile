CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./aphw1.o ./main.o ./aphw1_unittest.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./aphw1.o: ./aphw1.cpp
	$(CXX) $(CXXFLAGS) ./aphw1.cpp -o ./aphw1.o
./aphw1_unittest.o: ./aphw1_unittest.cpp
	$(CXX) $(CXXFLAGS) ./aphw1_unittest.cpp -o ./aphw1_unittest.o
./main.o: ./main.cpp
	$(CXX) $(CXXFLAGS) ./main.cpp -o ./main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
