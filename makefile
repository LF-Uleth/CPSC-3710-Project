# Makefile for OpenGL/GLUT program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Libraries to link
LIBS = -lGL -lGLU -lglut

# Source and output
SRC = robot.cpp
OUT = robot

# Default target
all: $(OUT)

# Build rule
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

# Clean up build files
clean:
	rm -f $(OUT)
