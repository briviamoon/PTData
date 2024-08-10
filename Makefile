# Detect the operating system
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    DETECTED_OS := $(shell uname -s)
endif

# Set variables based on the detected OS
ifeq ($(DETECTED_OS),Windows)
    CC := gcc
    RM := del /Q
    EXE := .exe
    GTK_PATH := C:\gtk-build\gtk\x64\release
    MSYS2_PATH := C:\msys64\mingw64

    CFLAGS := `pkg-config --cflags gtk+-3.0`

    LDFLAGS := `pkg-config --libs gtk+-3.0`
else
    CC := gcc
    RM := rm -f
    EXE :=
    CFLAGS := `pkg-config --cflags gtk+-3.0` -I./include
    LDFLAGS := `pkg-config --libs gtk+-3.0` -lsqlite3
endif

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
EXEC := physio_Data$(EXE)

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(subst /,\,$(OBJ)) $(EXEC)
