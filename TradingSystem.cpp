#include "TradingSystem.h"
#include <cstdlib> 
#include <ctime>   

// Implementacja SignalGenerator
SignalGenerator::SignalGenerator() {

}

SignalGenerator::~SignalGenerator() {}

int SignalGenerator::generateSignal(double price) {

    return (std::rand() % 2 == 0) ? -1 : 1;
}

//Implementacja TradingStrategy 

TradingStrategy::TradingStrategy(const std::vector<double>& p) : prices(p) {
}

TradingStrategy::~TradingStrategy() {}

void TradingStrategy::execute() {
    signals.clear();
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
