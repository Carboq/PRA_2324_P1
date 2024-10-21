#include "Square.h"

    bool Square::check(Point2D* vertices) {
        return (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2])) && 
               (Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[2], vertices[3])) &&
               (Point2D::distance(vertices[2], vertices[3]) == Point2D::distance(vertices[3], vertices[0]));
    }
    Square::Square() : Rectangle() {
        vs = new Point2D[4];
        vs[0] = Point2D(-1, 1);
        vs[1] = Point2D(1, 1);
        vs[2] = Point2D(1, -1);
        vs[3] = Point2D(-1, -1);
    }
    Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
        if (!check(vertices)) {
            throw std::invalid_argument("Vertices no forman un cuadrado");
        }
    }
    void Square::set_vertices(Point2D* vertices) {
        if (check(vertices)) {
            for (int i = 0; i < 4; i++) {
                vs[i] = vertices[i];
            }
        } else {
            throw std::invalid_argument("Vertices no forman un cuadrado");
        }
    }
    std::ostream& operator<<(std::ostream &out, const Square &square) {
        out << "Square with vertices " << square.vs[0] << ", " << square.vs[1] << ", " << square.vs[2] << ", " << square.vs[3] << " and color " << square.color;
        return out;
    }