#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"
#include <iostream>

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);
    // Attributes
public:
    Square();  
    Square(std::string color, Point2D* vertices);
    void set_vertices(Point2D* vertices) override;
    friend std::ostream& operator<<(std::ostream &out, const Square &square);
    // Constructor
};

#endif // SQUARE_H