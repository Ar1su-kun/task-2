CFLAGS = -g -fsanitize=address,leak

prog.out: main.c list.o input.o
	gcc -g $^ -o $@ $(CFLAGS)
input.o: input.c input.h
	gcc -c $< -o $@ $(CFLAGS)
list.o: list.c list.h
	gcc -c $< -o $@ $(SFLAGS)
