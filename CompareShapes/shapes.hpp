/* COPYRIGHT shape class
 * This file defines shapes class.
 * 
*/
#ifndef COMPARESHAPES_SHAPES_HPP_
#define COMPARESHAPES_SHAPES_HPP_

class Shape {
 protected:
    int a;
    int b;
 public:
    Shape(int _a, int _b):a(_a), b(_b) {}
    virtual int area() const = 0;
    virtual int perimeter() const = 0;
    bool operator==(const Shape &other);
    bool operator<(const Shape &other);
    bool operator>(const Shape &other);
};

class Rectangle : public Shape {
 public:
    Rectangle(int width, int height) : Shape(width, height) {}
    int area() const override;
    int perimeter() const override;
};

class Circle : public Shape {
 public:
    explicit Circle(int r) : Shape(r, 0) {}
    int area() const override;
    int perimeter() const override;
};

class Triangle : public Shape {
 public:
    Triangle(int base, int height) : Shape(base, height) {}
    int area() const override;
    int perimeter() const override;
};

#endif  // COMPARESHAPES_SHAPES_HPP_
