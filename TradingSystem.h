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
    std::vector<int> signals; // Przechowuje wygenerowane sygnały

public:
    // Konstruktor przyjmujący wektor cen
    TradingStrategy(const std::vector<double>& p);
    ~TradingStrategy();

    // Główna metoda wykonująca strategię
    void execute();

    // Getters i Setters
    void setPrices(const std::vector<double>& p);
    std::vector<double> getPrices() const;

    // Metoda pomocnicza do pobrania wyników (dla testów)
    std::vector<int> getSignals() const;
};