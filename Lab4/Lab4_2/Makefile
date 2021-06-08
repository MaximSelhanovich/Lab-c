CC = gcc
CFLAGS = -pedantic -Wall
LIBS = 
OBJ = Lab4_2.c
OBJ_TEST = Lab4_2.c
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright

Lab4_2: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab4_2

CheckValgrind:
    ./Lab4_2

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab4_2 CheckValgrind CheckLinter

.PHONY: clean
clean:
	del *.exe
