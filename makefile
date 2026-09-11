make:
	gcc *.c -o main
	./main

valgrind:
	valgrind -s --leak-check=full ./main
