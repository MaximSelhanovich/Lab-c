CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab6.c Tree.c
OBJ_TEST = Lab6_Test.c $(OBJ)
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright

Lab6: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab6
	./Lab6


Lab6_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab6_Test -Dmain=_main $(LIBS)
 
	./Lab6_Test 

CheckValgrind:
    valgrind ./Lab6_Test
	valgrind ./Lab6

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab6 Lab6_Test

.PHONY: clean
clean:
	del *.exe