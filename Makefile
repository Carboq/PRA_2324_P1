Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

clean:
	rm -r *.o *.gch bin
