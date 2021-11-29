GCC=gcc
CFLAGS=-c -I.
shell: main.o functions.o header.h
	$(GCC) -o shell main.o functions.o 
main.o: main.c
	$(GCC) $(CFLAGS) main.c 
functions.o: functions.c
	$(GCC) $(CFLAGS) functions.c 	
	
.PHONY: debug
debug: DFLAGS = -g
debug: clean alexa

.PHONY: sanitize
sanitize: DFLAGS = -fsanitize=address,undefined
sanitize: clean shell
.PHONY: clean
clean:
	rm -f *.o shell