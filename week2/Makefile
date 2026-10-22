CC	= gcc
CFLAGS	= -Wall -Wextra -g
OBJS	= main.o mystr.o

app: $(OBJS)
	$(CC) $(CFLAGS) -o app $(OBJS)

%.o: %.c mystr.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f app $(OBJS)
