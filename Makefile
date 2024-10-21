Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp
	
Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp

Square.o: Square.h Square.cpp
	g++ -c Square.cpp
bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o

clean:
	rm -r *.o *.gch bin
