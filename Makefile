
CC=clang
CFLAGS=-Wno-deprecated-declarations -framework GLUT -framework OpenGL -framework Carbon -o

all: A01

main: main.o 