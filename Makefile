vocab: menus.o vocab.o utils.o
	gcc -o vocab menus.o vocab.o utils.o

menus.o: menus.c
	gcc -c menus.c

vocab.o: vocab.c
	gcc -c vocab.c

utils.o: utils.c
	gcc -c utils.c

.PHONY: clean

clean:
	rm menus.o
	rm vocab.o
	rm utils.o
	rm vocab
