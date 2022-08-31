prog=wam

ccflags=-pthread
ldflags=-pthread -lX11 -lfltk

include ../GNUmakefile

try: main.o libdeq.so lawn.o lawnimp.o mole.o mtq.o
	g++ -o $@ $^ $(ldflags) -L. -ldeq -Wl,-rpath=.