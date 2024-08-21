CFLAGS=-g -Wall -Wextra -std=c11 -pedentic 
heap: main.c
	$(CC) $(CLAGS) -o heap main.c
clean:
	rm -f heap
