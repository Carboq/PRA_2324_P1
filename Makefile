Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

clean:
	rm -r *.o *.gch bin
