#pragma once
#include <cmath>

// Klasa bazowa
class Shape {
public:

    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Klasa pochodna: Koło
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    
    double area() const override;
    double perimeter() const override;

    double getRadius() const;
    void setRadius(double r);
};

// Klasa pochodna: Prostokąt
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);

    double area() const override;
    double perimeter() const override;

    double getWidth() const;
    void setWidth(double w);
    
    double getHeight() const;
    void setHeight(double h);
};
