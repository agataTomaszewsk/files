#include "Shapes.h"
#include <iostream>

// Definicja PI w razie gdyby kompilator nie miał M_PI (np. starsze wersje MSVC)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --- Implementacja Circle ---

Circle::Circle(double r) : radius(r) {}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    if (r >= 0) {
        radius = r;
    } else {
        std::cerr << "Blad: Promien nie moze byc ujemny.\n";
    }
}

// --- Implementacja Rectangle ---

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

double Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(double w) {
    if (w >= 0) width = w;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(double h) {
    if (h >= 0) height = h;
}