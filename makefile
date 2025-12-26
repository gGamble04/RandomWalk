CC = gcc
CFLAGS = `sdl2-config --cflags --libs` 

# Default target
RandomWalk: main.c RandomWalk.c ColorFormat/ColorFormat.c
	$(CC) main.c RandomWalk.c ColorFormat/ColorFormat.c -o RandomWalk $(CFLAGS)

# Strict target
strict: main.c RandomWalk.c ColorFormat/ColorFormat.c
	$(CC) -Wall -Wextra -Werror main.c RandomWalk.c ColorFormat/ColorFormat.c -o RandomWalk $(CFLAGS)

# Debug target
debug: main.c RandomWalk.c ColorFormat/ColorFormat.c
	$(CC) -g -Wall -Wextra main.c RandomWalk.c ColorFormat/ColorFormat.c -o RandomWalk $(CFLAGS)

# Clean target
clean:
	rm -f ./RandomWalk

.PHONY: clean strict