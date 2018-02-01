APP=main

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	gcc -o ${APP}.exe ${APP}.c interface.c

run:
	./${APP}.exe
