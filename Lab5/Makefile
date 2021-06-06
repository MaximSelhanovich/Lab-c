CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab5.c DigitRank.c BigInteger.c
OBJ_TEST = Lab5_Test.c $(OBJ)
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright,-runtime/int

Lab5: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -O0 -o Lab5

Lab5_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab5_Test -Dmain=_main $(LIBS)

CheckValgrind:
	valgrind --leak-check=full ./Lab5_Test
	valgrind ./Lab5

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab5 Lab5_Test CheckValgrind CheckLinter

.PHONY: clean
clean:
	del *.o
