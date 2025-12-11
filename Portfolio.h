#pragma once
#include <vector>
#include <iostream>
#include "Instruments.h"

class Portfolio {
private:
    std::vector<Instrument*> instruments;

public:
    Portfolio();
    ~Portfolio(); 

    Portfolio(const Portfolio&) = delete;
    Portfolio& operator=(const Portfolio&) = delete;

    void addInstrument(Instrument* inst);
    void removeInstrument(const std::string& symbol); 
    double totalValue() const;
    void display() const;
};
