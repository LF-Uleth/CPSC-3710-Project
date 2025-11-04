
CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

LIBS = -lGL -lGLU -lglut

SRC = robot.cpp
OUT = robot
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)
