// Definiujemy DEBUG przed dołączeniem testing.h, aby makra ASSERT działały
#define DEBUG 1 

#include "testing.h"
#include "Instruments.h"
#include <iostream>

// Testy dla klasy Stock
void testStock() {
    INFO("Testowanie klasy Stock");

    Stock s("NVDA", 450.0);
    
    // Sprawdzenie konstruktora i gettera z klasy bazowej
    ASSERT(s.getSymbol() == "NVDA");
    ASSERT_APPROX_EQUAL(s.price(), 450.0, 0.01);

    // Sprawdzenie setterów
    s.setSymbol("NVIDIA");
    s.setPrice(460.5);

    ASSERT(s.getSymbol() == "NVIDIA");
    ASSERT_APPROX_EQUAL(s.price(), 460.5, 0.01);
}

// Testy dla klasy Bond
void testBond() {
    INFO("Testowanie klasy Bond");

    Bond b("US_TREASURY", 1000.0);

    ASSERT(b.getSymbol() == "US_TREASURY");
    ASSERT_APPROX_EQUAL(b.price(), 1000.0, 0.01);
    ASSERT_APPROX_EQUAL(b.getFaceValue(), 1000.0, 0.01);

    b.setFaceValue(1100.0);
    ASSERT_APPROX_EQUAL(b.price(), 1100.0, 0.01);
}

// Testy polimorfizmu (wskaźnik na klasę bazową)
void testPolymorphism() {
    INFO("Testowanie polimorfizmu");

    Instrument* i1 = new Stock("ABC", 10.0);
    Instrument* i2 = new Bond("DEF", 100.0);

    // Wywołanie metod wirtualnych
    ASSERT_APPROX_EQUAL(i1->price(), 10.0, 0.01);
    ASSERT_APPROX_EQUAL(i2->price(), 100.0, 0.01);

    delete i1;
    delete i2;
}

int main() {
    // Włączenie logów debugowania
    setDebugEnabled(true);

    // Uruchomienie testów z frameworka testing.h
    TEST(testStock);
    TEST(testBond);
    TEST(testPolymorphism);

    return 0;
}