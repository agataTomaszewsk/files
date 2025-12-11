#define DEBUG 1
#include "testing.h"
#include "Shapes.h"
#include <iostream>

void testCircle() {
    INFO("Testowanie klasy Circle");

    double r = 5.0;
    Circle c(r);

    // Oczekiwane pole: pi * 5^2 = ~78.539
    double expectedArea = 3.14159 * 25;
    // Oczekiwany obwód: 2 * pi * 5 = ~31.415
    double expectedPerim = 2 * 3.14159 * 5;

    ASSERT_APPROX_EQUAL(c.area(), expectedArea, 0.01);
    ASSERT_APPROX_EQUAL(c.perimeter(), expectedPerim, 0.01);

    // Test settera
    c.setRadius(10.0);
    ASSERT_APPROX_EQUAL(c.area(), 314.159, 0.1);
}

void testRectangle() {
    INFO("Testowanie klasy Rectangle");

    Rectangle rect(4.0, 5.0);

    // Pole: 4 * 5 = 20
    ASSERT_APPROX_EQUAL(rect.area(), 20.0, 0.01);
    // Obwód: 2 * (4 + 5) = 18
    ASSERT_APPROX_EQUAL(rect.perimeter(), 18.0, 0.01);

    // Test setterów
    rect.setWidth(2.0);
    rect.setHeight(3.0);
    // Nowe pole: 2 * 3 = 6
    ASSERT_APPROX_EQUAL(rect.area(), 6.0, 0.01);
}

void testPolymorphism() {
    INFO("Testowanie polimorfizmu Shapes");

    // Tworzymy tablicę wskaźników do klasy bazowej
    Shape* shapes[2];
    shapes[0] = new Circle(1.0);       // Promień 1
    shapes[1] = new Rectangle(2.0, 3.0); // 2x3

    // Sprawdzamy pole koła (pi * 1^2 = ~3.14)
    ASSERT_APPROX_EQUAL(shapes[0]->area(), 3.14159, 0.001);

    // Sprawdzamy pole prostokąta (2 * 3 = 6)
    ASSERT_APPROX_EQUAL(shapes[1]->area(), 6.0, 0.001);

    // Czyszczenie pamięci
    delete shapes[0];
    delete shapes[1];
}

int main() {
    setDebugEnabled(true);

    TEST(testCircle);
    TEST(testRectangle);
    TEST(testPolymorphism);

    return 0;
}