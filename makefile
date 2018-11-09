all: signal.o
	touch intercepter.txt 
	gcc signal.o 
	
run:
	./a.out
clean:
	rm *.o 
	rm intercepter.txt
signal.o: signal.c
	gcc -c signal.c
