APP=what_will_it_print

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	gcc -Wall -o ${APP}.exe ${APP}.c

run:
	./${APP}.exe
