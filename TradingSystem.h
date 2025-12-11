#pragma once
#include <vector>
#include <iostream>

// Klasa generująca sygnały
class SignalGenerator {
public:
    SignalGenerator();
    ~SignalGenerator();

    // Generuje losowy sygnał (-1 lub 1) na podstawie ceny
    int generateSignal(double price);
};

// Klasa strategii handlowej
class TradingStrategy {
private:
    std::vector<double> prices;
    SignalGenerator generator;
    std::vector<int> signals; 
public:
   
    TradingStrategy(const std::vector<double>& p);
    ~TradingStrategy();

    void execute();

    void setPrices(const std::vector<double>& p);
    std::vector<double> getPrices() const;

    std::vector<int> getSignals() const;
};
