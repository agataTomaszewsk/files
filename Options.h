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

    // 1. Wersja podstawowa (czysto wirtualna)
    virtual double payoff(double spotPrice) const = 0;

    // 2. Wersja przeciążona (z dyskontowaniem)
    double payoff(double spotPrice, double discountFactor) const;

    // Getters / Setters
    double getStrike() const;
    void setStrike(double k);

    double getMaturity() const;
    void setMaturity(double t);
};

// Opcja Europejska Kupna (Call)
class EuropeanCall : public Option {
public:
    // --- KLUCZOWA POPRAWKA ---
    // Przywracamy widoczność metody payoff(double, double) z klasy bazowej
    using Option::payoff; 

    EuropeanCall(double strikePrice, double maturityTime);
    
    // Implementacja wersji z jednym argumentem
    double payoff(double spotPrice) const override;
};

// Opcja Europejska Sprzedaży (Put)
class EuropeanPut : public Option {
public:
    // --- KLUCZOWA POPRAWKA ---
    using Option::payoff;

    EuropeanPut(double strikePrice, double maturityTime);

    double payoff(double spotPrice) const override;
};