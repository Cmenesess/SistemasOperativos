GCC=gcc
CFLAGS=-c -I.
proceso: procesos.o
	$(GCC) -o proceso procesos.o
procesos.o: procesos.c
	$(GCC) $(CFLAGS) procesos.c 
	
.PHONY: debug
debug: DFLAGS = -g
debug: clean alexa

.PHONY: sanitize
sanitize: DFLAGS = -fsanitize=address,undefined
sanitize: clean alexa
.PHONY: clean
clean:
	rm -f *.o shell
