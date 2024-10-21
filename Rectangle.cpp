       
#include "Rectangle.h"

double Rectangle::area() const {
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const {
    return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < 4; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << "Rectangle con vertices: " << vs[0] << ", " << vs[1] << ", " << vs[2] << ", " << vs[3] << " y color " << color << std::endl;
}

bool Rectangle::check(Point2D* vertices) {
    return (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3])) && 
           (Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[3], vertices[0]));
}

Rectangle::Rectangle() : Shape() {
    vs = new Point2D[4];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    vs = new Point2D[4];
    if (check(vertices)) {
        for (int i = 0; i < 4; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("Vertices no forman un rectángulo");
    }
}


Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
    vs = new Point2D[4];
    for (int i = 0; i < 4; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= 4) {
        throw std::invalid_argument("Índice de vértice no válido");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const{
    if (ind < 0 || ind >= 4) {
        throw std::out_of_range("Índice de vértice no válido");
    }
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (check(vertices)) {
        for (int i = 0; i < 4; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("Vertices no forman un rectángulo");
    }
}
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs;
        vs = new Point2D[4];
        color = r.color;
        for (int i = 0; i < 4; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectangle con vertices: " << r.vs[0] << ", " << r.vs[1] << ", " << r.vs[2] << ", " << r.vs[3] << " y color " << r.color;
    return out;
}

        




    



    