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
        // Sprawdzamy czy sygnał jest poprawny 
        bool isValid = (sig == 1 || sig == -1);
        ASSERT(isValid);
    }
}

void testTradingStrategy() {
    INFO("Testowanie TradingStrategy");
    
    std::vector<double> marketPrices = {100.5, 101.0, 99.5, 102.0};
    TradingStrategy strategy(marketPrices);

    ASSERT(strategy.getPrices().size() == 4);
    ASSERT_APPROX_EQUAL(strategy.getPrices()[0], 100.5, 0.01);


    strategy.execute();

    std::vector<int> results = strategy.getSignals();
    ASSERT(results.size() == 4);

    for(int sig : results) {
        bool isValid = (sig == 1 || sig == -1);
        ASSERT(isValid);
    }


    std::vector<double> newPrices = {50.0, 60.0};
    strategy.setPrices(newPrices);
    strategy.execute();
    
    ASSERT(strategy.getSignals().size() == 2);
}

int main() {

    std::srand(std::time(0));
    setDebugEnabled(true);

    TEST(testSignalGenerator);
    TEST(testTradingStrategy);

    return 0;
}
