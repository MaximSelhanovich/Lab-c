#You know the rules and so do I
#Lab2_1: Lab2_1.c
#	gcc Lab2_1.c -pedantic -std=c89 -o Lab2_1.exe
#
#Lab2_1_Test: Lab2_1.c Lab2_1_Test.c
#	gcc Lab2_1.c Lab2_1_Test.c -pedantic -std=c89 -o Lab2_1_Test.exe -Dmain=_main -lm


CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = -lm
OBJ = Lab2_1.c Lab2_1_Test.c

Lab2_1: Lab2_1.c
	$(CC) $(CFLAGS) Lab2_1.c -o Lab1_2.exe
Lab2_1_Test: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab2_1_Test.exe -Dmain=_main $(LIBS)