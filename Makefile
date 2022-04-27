lab3: src/main.cpp FileOption.o aggregationOption.o
	g++ src/main.cpp FileOption.o aggregationOption.o -o lab3 && ./lab3 data/1115.csv data/3115.csv data/3130.csv

	
FileOption.o: src/FileOption.cpp
	g++ -c src/FileOption.cpp -o FileOption.o

aggregationOption.o: src/aggregationOption.cpp
	g++ -c src/aggregationOption.cpp -o aggregationOption.o

clean:
	rm -f lab3 *.o
