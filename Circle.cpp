#include "Circle.h"

    double Circle::area() const{
            return 3.1416 * radius*radius;
        }
        double Circle::perimeter() const {
            return 2 * 3.1416 * radius;
        }
        void Circle::translate(double incX, double incY) {
            center.x += incX;
            center.y += incY;
        }
        void Circle::print() {
            std::cout << "Circle at " << center << " with radius " << radius << " and color " << color << std::endl;
        }
        Circle::Circle() : Shape(), center{0, 0}, radius(1) {}
        Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}
        Point2D Circle::get_center() const {
            return center;
        }
        void Circle::set_center(Point2D p) {
            center = p;
        }
        double Circle::get_radius() const {
            return radius;
        }
        void Circle::set_radius(double r) {
            radius = r;
        }
        std::ostream& operator<<(std::ostream &out, const Circle &c) {
            out << "Circle at " << c.center << " with radius " << c.radius << " and color " << c.color;
            return out;
        }