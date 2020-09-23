
all: config
	make -C src
	mv src/nw-* .

config:
	echo "# Configuration for make" > config
	echo "OS= `uname`"  >> config
	echo "CC=gcc" >> config
	echo "CFLAGS=-std=c99 -Wall -Wextra `pkg-config --cflags raylib`" >> config
	echo "LIBS= `pkg-config --libs raylib`" >> config

clean:
	make -C src clean
