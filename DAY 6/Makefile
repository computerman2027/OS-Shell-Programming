CC = gcc
SRC = $(wildcard ex*.c)
EXE = $(SRC:.c=)

all: $(EXE)

%: %.c
	$(CC) $< -o $@

clean:
	rm -f $(EXE)
