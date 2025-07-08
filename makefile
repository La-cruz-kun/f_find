CFLAGS = -ggdb -Wall -Wextra -pedantic
ffind: main.c
	gcc main.c $(CFLAGS) -o ffind
