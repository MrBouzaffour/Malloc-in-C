CFLAGS=-Wall -Wextra -std=c11 -pedentic -ggdb
heap: main.c
	$(CC) $(CLAGS) -o heap main.c
clean:
	rm -f heap
