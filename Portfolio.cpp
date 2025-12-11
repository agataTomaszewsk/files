#include "Portfolio.h"

Portfolio::Portfolio() {
}

Portfolio::~Portfolio() {
    std::cout << "DEBUG: Niszczenie portfela i czyszczenie pamieci\n";
    for (Instrument* inst : instruments) {
        delete inst;
    }
    instruments.clear();
}

void Portfolio::addInstrument(Instrument* inst) {
    instruments.push_back(inst);
}

void Portfolio::removeInstrument(const std::string& symbol) {
    for (auto it = instruments.begin(); it != instruments.end(); ) {
        if ((*it)->getSymbol() == symbol) {
            delete *it; 
            it = instruments.erase(it); 
            std::cout << "Usunieto instrument: " << symbol << "\n";
        } else {
            ++it;
        }
    }
}

double Portfolio::totalValue() const {
    double total = 0.0;
    for (const Instrument* inst : instruments) {
        total += inst->price(); 
    }
    return total;
}

void Portfolio::display() const {
    std::cout << " SZCZEGOLY PORTFELA \n";
    for (const Instrument* inst : instruments) {
        std::cout << "Instrument: " << inst->getSymbol() 
                  << " | Cena: " << inst->price() << "\n";
    }
    std::cout << "Laczna wartosc: " << totalValue() << "\n";
    std::cout << "--------------------------\n";
}
