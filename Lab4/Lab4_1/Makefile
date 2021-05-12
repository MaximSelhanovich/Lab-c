CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab4_1.c
OBJ_TEST = Lab4_1.c Lab4_1_Test.c
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright

Lab4_1: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab4_1

Lab4_1_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab4_1_Test -Dmain=_main $(LIBS)

CheckValgrind:
	echo "first\nWell yes\nToLoWeRtEsT\ntolowertest\nSoMe text6789 \ bage laGa fdUghUjU\n t37tin9 <>/.#55vg sOmE\n thrt some .,.,hubhy/.fdsghuju\n\n" > input.txt 
	valgrind ./Lab4_1_Test < input.txt

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab4_1 Lab4_1_Test CheckValgrind CheckLinter

.PHONY: clean
clean:
	del *.exe
