APP=mutant

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	gcc -o ${APP}.exe ${APP}.c

run:
	./${APP}.exe
