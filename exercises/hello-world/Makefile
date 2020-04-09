.PHONY: clean

all: serial openmp run

# Serial version.
serial:
	gcc -Wall -g -o hello main.c -lm

# OpenMP parallel version.
openmp:
	gcc -Wall -g -fopenmp -o hellomp main.c -lm

run: serial openmp
	@echo "Serial"
	@echo "----------------------------------------"
	./hello
	@echo
	@echo "OpenMP"
	@echo "----------------------------------------"
	./hellomp

clean:
	rm -f hello hellomp
