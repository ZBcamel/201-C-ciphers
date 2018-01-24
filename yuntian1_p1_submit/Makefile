squeue_test: squeue.o squeue_test.o
	gcc -Wall -std=c99 -o squeue squeue_test.o squeue.o

squeue_test.o: squeue.h squeue_test.c
	gcc -Wall -std=c99 -c -o squeue_test.o squeue_test.c

queue.o: squeue.h squeue.c
	gcc -Wall -std=c99 -c -o squeue.o squeue.c

clean:
	rm -f *.o
	rm -f squeue
mem:
	valgrind --leak-check=yes ./squeue
run:
	./squeue
