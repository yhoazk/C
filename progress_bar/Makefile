APP=progress_bar

all: clean comp run

clean:
	rm -rf ./${APP}.exe 

comp:
	g++ -g -o ${APP}.exe ${APP}.c

run:
	./${APP}.exe
