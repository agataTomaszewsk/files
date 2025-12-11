#define DEBUG 1
#include "testing.h"
#include "Options.h"
#include <iostream>

void testCallOption() {
    INFO("Testowanie European Call Option");

    double strike = 100.0;
    EuropeanCall call(strike, 1.0);

    // Scenariusz 1: Spot > Strike (In the money)
    // Cena 120, Strike 100 -> Zysk 20
    ASSERT_APPROX_EQUAL(call.payoff(120.0), 20.0, 0.01);

    // Scenariusz 2: Spot < Strike (Out of the money)
    // Cena 80, Strike 100 -> Zysk 0
    ASSERT_APPROX_EQUAL(call.payoff(80.0), 0.0, 0.01);

    // Scenariusz 3: Test przeciążenia (z dyskontowaniem)
    // Payoff 20, Discount Factor 0.9 -> Wynik 18.0
    ASSERT_APPROX_EQUAL(call.payoff(120.0, 0.9), 18.0, 0.01);
}

void testPutOption() {
    INFO("Testowanie European Put Option");

    double strike = 100.0;
    EuropeanPut put(strike, 1.0);

    // Scenariusz 1: Spot < Strike (In the money)
    // Cena 80, Strike 100 -> Zysk 20
    ASSERT_APPROX_EQUAL(put.payoff(80.0), 20.0, 0.01);

    // Scenariusz 2: Spot > Strike (Out of the money)
    // Cena 120, Strike 100 -> Zysk 0
    ASSERT_APPROX_EQUAL(put.payoff(120.0), 0.0, 0.01);
}

void testPolymorphism() {
    INFO("Testowanie polimorfizmu Opcji");

    Option* opt1 = new EuropeanCall(100.0, 0.5);
    Option* opt2 = new EuropeanPut(100.0, 0.5);

    // Sprawdzamy dla ceny spot = 110
    // Call (110 - 100) = 10
    // Put (100 - 110) < 0 -> 0
    ASSERT_APPROX_EQUAL(opt1->payoff(110.0), 10.0, 0.01);
    ASSERT_APPROX_EQUAL(opt2->payoff(110.0), 0.0, 0.01);

    // Sprawdzamy settery przez wskaźnik bazowy
    opt1->setStrike(105.0);
    // Call (110 - 105) = 5
    ASSERT_APPROX_EQUAL(opt1->payoff(110.0), 5.0, 0.01);

    delete opt1;
    delete opt2;
}

int main() {
    setDebugEnabled(true);

    TEST(testCallOption);
    TEST(testPutOption);
    TEST(testPolymorphism);

    return 0;
}