application: staticlib
	gcc Normalverteilung.c -lgau�verteilungstaticlib -lm

staticlib:
	gcc Gau�verteilungSTATICLIB.c -c
	ar -crs libGau�verteilungSTATICLIB.a Gau�verteilungSTATICLIB.o
	sudo cp Gau�verteilungSTATICLIB.h /usr/include
	sudo cp libGau�verteilungSTATICLIB.a /usr/lib
