CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++20 -Wold-style-cast
TARGET = simulator
SRCS = order.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
