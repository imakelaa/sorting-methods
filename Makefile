
CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra -gdwarf-4 -g
EXEC = sorting
OBJS= sorting.o heap.o stats.o shell.o quick.o batcher.o set.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(EXEC) $(OBJS)

format:
	clang-format -i -style=file *.[ch]

scan-build: clean
	scan-build --use-cc=$(CC) make
