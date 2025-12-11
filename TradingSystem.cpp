#include "TradingSystem.h"
#include <cstdlib> // dla rand()
#include <ctime>   // dla time()

// --- Implementacja SignalGenerator ---

SignalGenerator::SignalGenerator() {
    // Inicjalizacja ziarna losowości (w prostym przypadku)
    // Uwaga: w profesjonalnym kodzie robi się to raz w main, 
    // ale tutaj dla pewności, że działa, zostawiamy konstruktor pusty,
    // a srand wywołamy w main.
}

SignalGenerator::~SignalGenerator() {}

int SignalGenerator::generateSignal(double price) {
    // Ignorujemy 'price' w logice losowania, ponieważ zadanie prosi o
    // "random trading signals" (losowe sygnały), ale wymaga parametru price.
    
    // Losuje 0 lub 1. Jeśli 0 -> zwróć -1 (Sell), w przeciwnym razie 1 (Buy)
    return (std::rand() % 2 == 0) ? -1 : 1;
}

// --- Implementacja TradingStrategy ---

TradingStrategy::TradingStrategy(const std::vector<double>& p) : prices(p) {
}

TradingStrategy::~TradingStrategy() {}

void TradingStrategy::execute() {
    signals.clear(); // Czyścimy poprzednie sygnały
    std::cout << "--- Wykonywanie Strategii ---\n";
    
    for (double price : prices) {
        int signal = generator.generateSignal(price);
        signals.push_back(signal);
        
        std::cout << "Cena: " << price << " -> Sygnal: " 
                  << (signal == 1 ? "KUPUJ (1)" : "SPRZEDAWAJ (-1)") << "\n";
    }
    std::cout << "-----------------------------\n";
}

void TradingStrategy::setPrices(const std::vector<double>& p) {
    prices = p;
}

std::vector<double> TradingStrategy::getPrices() const {
    return prices;
}

std::vector<int> TradingStrategy::getSignals() const {
    return signals;
}