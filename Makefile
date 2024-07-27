CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -I./include
LDFLAGS = `pkg-config --libs gtk+-3.0` -lsqlite3
SRC = $(wildcard src/*.C)
OBJ = $(SRC:.c=.o)
EXEC = PTData