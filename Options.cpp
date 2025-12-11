#include "Options.h"

// --- Implementacja klasy bazowej Option ---

Option::Option(double strikePrice, double maturityTime) 
    : strike(strikePrice), maturity(maturityTime) {}

Option::~Option() {}

// Implementacja metody przeciążonej (z dyskontowaniem)
double Option::payoff(double spotPrice, double discountFactor) const {
    // Wywołuje wersję wirtualną (specyficzną dla Call lub Put) i dyskontuje
    return payoff(spotPrice) * discountFactor;
}

double Option::getStrike() const {
    return strike;
}

void Option::setStrike(double k) {
    strike = k;
}

double Option::getMaturity() const {
    return maturity;
}

void Option::setMaturity(double t) {
    maturity = t;
}

// --- Implementacja EuropeanCall ---

EuropeanCall::EuropeanCall(double strikePrice, double maturityTime)
    : Option(strikePrice, maturityTime) {}

double EuropeanCall::payoff(double spotPrice) const {
    // Payoff = max(Spot - Strike, 0)
    return std::max(spotPrice - strike, 0.0);
}

// --- Implementacja EuropeanPut ---

EuropeanPut::EuropeanPut(double strikePrice, double maturityTime)
    : Option(strikePrice, maturityTime) {}

double EuropeanPut::payoff(double spotPrice) const {
    // Payoff = max(Strike - Spot, 0)
    return std::max(strike - spotPrice, 0.0);
}