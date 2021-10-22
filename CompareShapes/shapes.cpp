/* COPYRIGHT shape class
 * This file implements shapes.
 * 
*/
#include "shapes.hpp"

#include <iostream>

#include <cmath>

bool Shape::operator==(const Shape &other) {
    bool equal = false;
    if (this->area() == other.area() &&
        this->perimeter() == other.perimeter()) {
        equal = true;
    }
    return equal;
}

bool Shape::operator>(const Shape &other) {
    bool bigger = false;
    if (this->area() > other.area() &&
        this->perimeter() > other.perimeter()) {
        bigger = true;
    }
    return bigger;
}

bool Shape::operator<(const Shape &other) {
    bool smaller = false;
    if (this->area() < other.area() &&
        this->perimeter() < other.perimeter()) {
        smaller = true;
    }
    return smaller;
}

int Rectangle::area() const  {
    return this->a * this->b;
}

int Rectangle::perimeter() const  {
    return (this->a + this->b) * 2;
}

int Triangle::area() const  {
    return (this->a * this->b) / 2;
}

int Triangle::perimeter() const  {
    return (this->a + this->b + static_cast<int>(std::sqrt(a*a + b*b)));
}

int Circle::area() const  {
    return static_cast<int>((this->a * this->a * M_PI));
}

int Circle::perimeter() const  {
    return static_cast<int>(this->a * 2 * M_PI);
}
