APP=unbuffered_tty

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	g++ -Wall -o ${APP}.exe ${APP}.c

run:
	./${APP}.exe
