# Compiler and compiler flags
CXX = g++

# Source files and target executable
SRCS = .\Array\custom_array.cpp test.cpp
TARGET = test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)