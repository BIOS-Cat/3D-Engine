check: clean test_suite.o 
	gcc -o test_suite test_suite.o `pkg-config --cflags --libs check`
	./test_suite

test_suite.o:
	gcc -Wall -std=c99 -c test_suite.c -o test_suite.o	
	
clean:
	rm -f *.o test_suite
