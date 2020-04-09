.PHONY: clean

all: serial openmp run

# Serial version.
serial:
	gcc -Wall -g -o montecarlo main.c -lm

# OpenMP parallel version.
openmp:
	gcc -Wall -g -fopenmp -o montecarlomp main.c -lm

run: serial openmp
	@echo "Serial VS OpenMP at       100,000 trials"
	@echo "----------------------------------------"
	/usr/bin/time -p ./montecarlo   100000
	/usr/bin/time -p ./montecarlomp 100000
	@echo
	@echo "Serial VS OpenMP at     1,000,000 trials"
	@echo "----------------------------------------"
	/usr/bin/time -p ./montecarlo   1000000
	/usr/bin/time -p ./montecarlomp 1000000
	@echo
	@echo "Serial VS OpenMP at    10,000,000 trials"
	@echo "----------------------------------------"
	/usr/bin/time -p ./montecarlo   10000000
	/usr/bin/time -p ./montecarlomp 10000000
	@echo
	@echo "Serial VS OpenMP at   100,000,000 trials"
	@echo "----------------------------------------"
	/usr/bin/time -p ./montecarlo   100000000
	/usr/bin/time -p ./montecarlomp 100000000

clean:
	rm -f montecarlo montecarlomp
