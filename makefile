CFLAGS = -std=c11 -Wall -Wextra -pedantic
main: main.c
	clang main.c $(CFLAGS) -o main
