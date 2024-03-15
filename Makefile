vocab: menus.o vocab.o utils.o file_writer.o
	gcc -o vocab menus.o vocab.o utils.o file_writer.o

menus.o: menus.c
	gcc -c menus.c

vocab.o: vocab.c
	gcc -c vocab.c

utils.o: utils.c
	gcc -c utils.c

file_writer.o: file_writer.c
	gcc -c file_writer.c

.PHONY: clean

clean:
	rm menus.o
	rm vocab.o
	rm utils.o
	rm file_writer.o
	rm vocab
