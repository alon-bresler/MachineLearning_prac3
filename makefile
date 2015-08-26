CC=g++
CCFLAGS=-std=c++11
LIBS=-lm

ML3: main.o
		$(CC) $(CCFLAGS) main.o -o ML3 $(LIBS)
				
main.o: main.cpp
		$(CC) $(CCFLAGS) main.cpp -c
	
clean: 
		@rm -f *.o
		@rm -f ML3
		
install: 
		@mv ML3 -/bin
