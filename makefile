compile: cat.c
	gcc -Wall -pedantic-errors -o cat cat.c

clean:
	rm cat
