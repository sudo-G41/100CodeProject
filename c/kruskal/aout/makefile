EXEC=main
CC=gcc
CFLAGS=-Wall

$(EXEC) : main.o
		$(CC) -o main main.o -L../lib -la
%.o : %.c
		$(CC) -c $(CFLAGS) -I../include $< -o $@

clean :
		rm main main.o
