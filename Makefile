CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = numerical_calculus
OBJS = main.o functions.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp functions.h
	$(CXX) $(CXXFLAGS) -c main.cpp

functions.o: functions.cpp functions.h
	$(CXX) $(CXXFLAGS) -c functions.cpp

clean:
	rm -f $(TARGET) $(OBJS)
