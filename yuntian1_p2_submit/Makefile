bucketstack_test: bucketstack.o bucketstack_test.o
	gcc -Wall -std=c99 -o bucketstack bucketstack_test.o bucketstack.o

bucketstack_test.o: bucketstack.h bucketstack_test.c
	gcc -Wall -std=c99 -c -o bucketstack_test.o bucketstack_test.c

queue.o: bucketstack.h bucketstack.c
	gcc -Wall -std=c99 -c -o bucketstack.o bucketstack.c

clean:
	rm -f *.o
	rm -f bucketstack
mem:
	valgrind --leak-check=yes ./bucketstack
run:
	./bucketstack
