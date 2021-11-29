GCC=gcc
CFLAGS=-c -I.
hiloss: hilos.o
	$(GCC) -o hiloss hilos.o -lpthread -lrt
hilos.o: hilos.c
	$(GCC) $(CFLAGS) hilos.c 
.PHONY: debug
debug: DFLAGS = -g
debug: clean alexa

.PHONY: sanitize
sanitize: DFLAGS = -fsanitize=address,undefined
sanitize: clean alexa
.PHONY: clean
clean:
	rm -f *.o shell
