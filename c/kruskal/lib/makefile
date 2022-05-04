CC=gcc
LIB=liba.a
OBJS = unionfind.o
CFLAGS=-Wall

$(LIB) : $(OBJS)
		$(AR) rv $@ $(OBJS)
%.o : %.c
		$(CC) -c $(CFLAGS) -I../include $< -o $@

clean :
		rm -f $(OBJS) $(LIB)