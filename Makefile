programa: Shape.o Circle.o
	g++ -o programa Shape.o Circle.o

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp
	g++ -c Circle.cpp

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

clean:
	rm -r *.o *.gch bin
