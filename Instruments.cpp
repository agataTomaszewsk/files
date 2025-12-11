#include "Instruments.h"

// --- Implementacja Instrument ---

Instrument::Instrument(const std::string& sym) : symbol(sym) {}

Instrument::~Instrument() {}

std::string Instrument::getSymbol() const {
    return symbol;
}

void Instrument::setSymbol(const std::string& sym) {
    symbol = sym;
}

// --- Implementacja Stock ---

Stock::Stock(const std::string& sym, double p) : Instrument(sym), sharePrice(p) {}

double Stock::price() const {
    return sharePrice;
}

void Stock::setPrice(double p) {
    sharePrice = p;
}

// --- Implementacja Bond ---

Bond::Bond(const std::string& sym, double val) : Instrument(sym), faceValue(val) {}

double Bond::price() const {
    return faceValue;
}

void Bond::setFaceValue(double val) {
    faceValue = val;
}

double Bond::getFaceValue() const {
    return faceValue;
}