bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p binç
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

clean:
	rm -r *.o *.gch bin
