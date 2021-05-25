CC = gcc
CFLAGS = -pedantic -Wall
LIBS = 
OBJ = Lab4_2.c
OBJ_TEST = Lab4_2.c Lab4_2_Test.c
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright

Lab4_2: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab4_2
	./Lab4_2

Lab4_2_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab4_2_Test -Dmain=_main $(LIBS)

	echo first-Well yesToLoWeRtEsTtolowertest > input.txt 
	./Lab4_2_Test < input.txt

CheckValgrind:
	echo "SoMe text6789 \\ bage laGa fdUghUjU \n t37tin9 <>/.#55vg sOmE\n thrt some .,.,hubhy/.fdsghuju\n\n" > input.txt

	Well yes" > input.txt
    ./Lab4_2_Test < input.txt

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab4_2 Lab4_2_Test CheckValgrind CheckLinter

.PHONY: clean
clean:
	del *.exe