#pragma once
#include <vector>
#include <iostream>
#include "Instruments.h"

class Portfolio {
private:
    // Wektor wskaźników do klasy bazowej Instrument
    std::vector<Instrument*> instruments;

public:
    Portfolio();
    ~Portfolio(); // Destruktor zwalniający pamięć

    // Blokujemy kopiowanie, aby uniknąć problemów z podwójnym usuwaniem wskaźników
    Portfolio(const Portfolio&) = delete;
    Portfolio& operator=(const Portfolio&) = delete;

    // Metody wymagane przez zadanie
    void addInstrument(Instrument* inst);
    void removeInstrument(const std::string& symbol); // Usuwa instrument po symbolu
    double totalValue() const;
    void display() const;
};