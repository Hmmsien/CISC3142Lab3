lab3: src/main.cpp FileOption.o aggregationOption.o
	g++ -Wall src/main.cpp FileOption.o aggregationOption.o -o lab3
	
FileOption.o: src/FileOption.cpp
	g++ -Wall -c src/FileOption.cpp -o FileOption.o

aggregationOption.o: src/aggregationOption.cpp
	g++ -Wall -c src/aggregationOption.cpp -o aggregationOption.o

clean:
	rm -f lab3 *.o
