CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab6.c Tree.c
OBJ_TEST = Lab6_Test.c $(OBJ)
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright

Lab6: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab6

Lab6_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab6_Test -Dmain=_main $(LIBS)

CheckValgrind:
	echo "my word\nSay my name\ndoom\naboba\nhi\nonion\ntopor\nmork\nend\n" > input.txt
	valgrind ./Lab6_Test < input.txt
	echo "someemos\nhelp\nme\nno\nwhy?\nklopplok\nend\n" > ni.txt
	valgrind ./Lab6 < ni.txt

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab6 Lab6_Test

.PHONY: clean
clean:
	del *.exe
