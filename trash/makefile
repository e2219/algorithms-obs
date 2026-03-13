CXX      := g++
STD      ?= c++20
CXXFLAGS := -g -std=$(STD)

TARGET := t
SRC    := trash_cpp.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGET)

