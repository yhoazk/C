all: clean comp run

clean:
	rm -rf *.exe

comp:
	gcc -Wall -g -o state_log.exe state_log.c

run:
	./state_log.exe < input 
