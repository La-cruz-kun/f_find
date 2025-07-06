CFLAGS = -Wall -Wextra -pedantic
main: main.c
	gcc main.c $(CFLAGS) -o main
