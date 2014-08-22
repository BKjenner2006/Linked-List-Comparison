CC = g++

binTreeCompare.exe: binTreeCompare.o
	$(CC) -o binTreeCompare.exe binTreeCompare.o

binTreeCompare.o: binTreeCompare.cc
	$(CC) -c binTreeCompare.cc

clean:
	rm *.o *.exe
