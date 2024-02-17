G=g++

myWC.exe: analyser.o main.o
	$(G) analyser.o main.o -o myWC.exe -std=c++20

%.o: %.cpp
	$(G) -c $< -o $@

run:
	./driver.exe

clean:
	rm *.o myWC.exe DEADJOE
