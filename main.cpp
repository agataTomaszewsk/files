#define DEBUG 1
#include "testing.h"
#include "TradingSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testSignalGenerator() {
    INFO("Testowanie SignalGenerator");
    SignalGenerator gen;

    // Testujemy wielokrotnie, aby upewnić się, że wynik to zawsze -1 lub 1
    for(int i = 0; i < 10; i++) {
        int sig = gen.generateSignal(100.0);
        // Sprawdzamy czy sygnał jest poprawny (musi być 1 albo -1)
        bool isValid = (sig == 1 || sig == -1);
        ASSERT(isValid);
    }
}

void testTradingStrategy() {
    INFO("Testowanie TradingStrategy");

    // Przygotowanie danych
    std::vector<double> marketPrices = {100.5, 101.0, 99.5, 102.0};
    TradingStrategy strategy(marketPrices);

    // Sprawdzenie gettera
    ASSERT(strategy.getPrices().size() == 4);
    ASSERT_APPROX_EQUAL(strategy.getPrices()[0], 100.5, 0.01);

    // Wykonanie strategii
    strategy.execute();

    // Sprawdzenie czy wygenerowano tyle sygnałów ile było cen
    std::vector<int> results = strategy.getSignals();
    ASSERT(results.size() == 4);

    // Sprawdzenie czy każdy wynik jest poprawny (-1 lub 1)
    for(int sig : results) {
        bool isValid = (sig == 1 || sig == -1);
        ASSERT(isValid);
    }

    // Test Settera
    std::vector<double> newPrices = {50.0, 60.0};
    strategy.setPrices(newPrices);
    strategy.execute();
    
    ASSERT(strategy.getSignals().size() == 2);
}

int main() {
    // Inicjalizacja generatora liczb losowych
    std::srand(std::time(0));
    setDebugEnabled(true);

    TEST(testSignalGenerator);
    TEST(testTradingStrategy);

    return 0;
}