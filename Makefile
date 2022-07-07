application: staticlib
	gcc Normalverteilung.c -lgauﬂverteilungstaticlib -lm

staticlib:
	gcc GauﬂverteilungSTATICLIB.c -c
	ar -crs libGauﬂverteilungSTATICLIB.a GauﬂverteilungSTATICLIB.o
	sudo cp GauﬂverteilungSTATICLIB.h /usr/include
	sudo cp libGauﬂverteilungSTATICLIB.a /usr/lib
