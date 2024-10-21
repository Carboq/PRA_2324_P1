#include "Shape.h"
#include <cctype>
#include <stdexcept>




Shape::Shape() : color("rojo") {}

Shape::Shape(std::string color){
        set_color(color);
}

std::string Shape::get_color() const {
    return color;
}
void Shape::set_color(std::string c){
        for (char ch : c) {
        // Si encontramos un carácter que no es una letra, devolvemos false
        if (!isalpha(ch)) {
            throw std::invalid_argument("Color no válido");
        }
    }
    color = c;
}



