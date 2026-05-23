CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = app.exe

SRCS = main.cpp LogAnalyzer.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q *.o $(TARGET)
