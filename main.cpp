#define DEBUG 1 
#include "testing.h"
#include "Instruments.h"
#include "Portfolio.h"
#include <iostream>

// --- Poprzednie testy ---
void testStock() {
    INFO("Testowanie klasy Stock");
    Stock s("NVDA", 450.0);
    ASSERT_APPROX_EQUAL(s.price(), 450.0, 0.01);
}

void testBond() {
    INFO("Testowanie klasy Bond");
    Bond b("US_TREASURY", 1000.0);
    ASSERT_APPROX_EQUAL(b.price(), 1000.0, 0.01);
}

// --- NOWY TEST DLA ZADANIA ---
void testPortfolio() {
    INFO("Testowanie klasy Portfolio");

    // Tworzymy portfel na stosie (automatycznie usunie się na końcu funkcji)
    Portfolio myPortfolio;

    // Tworzymy instrumenty dynamicznie (new)
    // Portfolio przejmuje odpowiedzialność za ich usunięcie (ownership)
    myPortfolio.addInstrument(new Stock("APPLE", 150.0));
    myPortfolio.addInstrument(new Stock("TESLA", 200.0));
    myPortfolio.addInstrument(new Bond("PL_BOND", 1000.0));

    // Wyświetlamy zawartość
    myPortfolio.display();

    // Sprawdzamy łączną wartość (150 + 200 + 1000 = 1350)
    ASSERT_APPROX_EQUAL(myPortfolio.totalValue(), 1350.0, 0.01);

    // Test usuwania instrumentu
    myPortfolio.removeInstrument("TESLA");
    
    // Sprawdzamy wartość po usunięciu (150 + 1000 = 1150)
    ASSERT_APPROX_EQUAL(myPortfolio.totalValue(), 1150.0, 0.01);

    std::cout << "Po usunieciu TESLA:\n";
    myPortfolio.display();
}

int main() {
    setDebugEnabled(true);

    TEST(testStock);
    TEST(testBond);
    TEST(testPortfolio); // Uruchomienie nowego testu

    return 0;
}