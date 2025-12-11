#pragma once
#include <cmath>

// Klasa bazowa (abstrakcyjna)
class Shape {
public:
    // Wirtualny destruktor jest konieczny przy polimorfizmie
    virtual ~Shape() {}

    // Metody czysto wirtualne (= 0)
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

// Klasa pochodna: Koło
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    
    // Nadpisujemy metody bazowe
    double area() const override;
    double perimeter() const override;

    // Gettery i Settery
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

    // Nadpisujemy metody bazowe
    double area() const override;
    double perimeter() const override;

    // Gettery i Settery
    double getWidth() const;
    void setWidth(double w);
    
    double getHeight() const;
    void setHeight(double h);
};