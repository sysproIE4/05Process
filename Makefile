timer : timer.c font.h Makefile
	cc -o timer timer.c font.c

clean :
	rm -f timer

