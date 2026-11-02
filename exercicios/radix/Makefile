CC = cc
CFLAGS = -O2 -std=c11 -Wall -Wextra -Wpedantic

.PHONY: all bench test clean

all: main benchmark

main: main.c process.c sufix.c process.h sufix.h item.h
	$(CC) $(CPPFLAGS) $(CFLAGS) main.c process.c sufix.c $(LDFLAGS) $(LDLIBS) -o $@

benchmark: benchmark.c process.c sufix.c process.h sufix.h item.h
	$(CC) $(CPPFLAGS) $(CFLAGS) benchmark.c process.c sufix.c $(LDFLAGS) $(LDLIBS) -o $@

tests/test_process: tests/test_process.c process.c process.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -I. tests/test_process.c process.c $(LDFLAGS) $(LDLIBS) -o $@

tests/test_radix: tests/test_radix.c msdRadix.c sufix.c msdRadix.h sufix.h item.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -I. tests/test_radix.c msdRadix.c sufix.c $(LDFLAGS) $(LDLIBS) -o $@

test: all tests/test_process tests/test_radix
	./tests/test_process
	./tests/test_radix
	sh tests/test_cli.sh

bench: benchmark
	./benchmark in/*.txt

clean:
	rm -f main benchmark tests/test_process tests/test_radix
