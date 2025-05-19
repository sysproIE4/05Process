timer : timer.c font.h font.c Makefile
	cc -o timer timer.c font.c

clean :
	rm -f timer

