check: clean test_suite.o
	$(CC) -o test_suite test_suite.o `pkg-config --cflags --libs check`
	./test_suite

test_suite.o:
	$(CC) -Wall -std=c99 -c test_suite.c -o test_suite.o	
	
clean:
	rm -f *.o test_suite
