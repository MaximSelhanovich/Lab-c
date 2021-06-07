CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab7.c Project.c ListOfTasks.c Task.c Date.c
OBJ_TEST = Lab7_Test.c $(OBJ)
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright

Lab7: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab7
	./Lab7

Lab7_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab7_Test -Dmain=_main $(LIBS)

CheckValgrind:
	echo "321\n2024\n-4\n2\nasdf\n29\n2022\n5\n28\n2026\n6\n30\n2026\n6\n30\nGet rekted\n2222\n2\n2\n2222\n\1\n1\n2345\n2\n2\n" > input.txt
	valgrind ./Lab7_Test < input.txt

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab7 Lab7_Test CheckValgrind CheckLinter

.PHONY: clean
clean:
	del *.exe
