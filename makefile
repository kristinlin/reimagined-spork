all: semspork.c
	gcc semspork.c
run: all
	./a.out -c 5
	./a.out -v
	./a.out -c 3
	./a.out -v
	./a.out -r
