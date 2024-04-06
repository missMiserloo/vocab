OBJECTS=menus.o vocab.o utils.o input.o
CFLAGS=-g

vocab: $(OBJECTS)
	gcc $(CFLAGS) -o vocab $(OBJECTS)

%.o: %.c
	gcc $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm *.o
	rm vocab
