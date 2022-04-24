.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	LSEA

LSEA:	LSEA.o cLSEA.o cNoLSEA.o
	g++ -o $@ $^

clean:
	rm *.o LSEA
	