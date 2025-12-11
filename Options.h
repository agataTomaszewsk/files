#pragma once
#include <algorithm> 

// Klasa bazowa
class Option {
protected:
    double strike;    // Cena wykonania (K)
    double maturity;  // Czas do wygaśnięcia (T)

public:
    Option(double strikePrice, double maturityTime);
    virtual ~Option();
    // Wersja podstawowa
    virtual double payoff(double spotPrice) const = 0;

    // Wersja z dyskontowaniem
    double payoff(double spotPrice, double discountFactor) const;

    double getStrike() const;
    void setStrike(double k);

    double getMaturity() const;
    void setMaturity(double t);
};

// Opcja Europejska Kupna (Call)
class EuropeanCall : public Option {
public:

    using Option::payoff; 

    EuropeanCall(double strikePrice, double maturityTime);
    
    double payoff(double spotPrice) const override;
};

// Opcja Europejska Sprzedaży (Put)
class EuropeanPut : public Option {
public:
    using Option::payoff;

    EuropeanPut(double strikePrice, double maturityTime);

    double payoff(double spotPrice) const override;
};
