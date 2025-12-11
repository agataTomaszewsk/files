#pragma once
#include <string>

// Klasa bazowa
class Instrument {
protected:
    std::string symbol;

public:
    Instrument(const std::string& sym);
    virtual ~Instrument(); // Wirtualny destruktor

    virtual double price() const = 0; // Metoda czysto wirtualna

    // Gettery i Settery
    std::string getSymbol() const;
    void setSymbol(const std::string& sym);
};

// Klasa pochodna: Akcja
class Stock : public Instrument {
private:
    double sharePrice;

public:
    Stock(const std::string& sym, double p);
    
    double price() const override;
    
    void setPrice(double p);
};

// Klasa pochodna: Obligacja
class Bond : public Instrument {
private:
    double faceValue;

public:
    Bond(const std::string& sym, double val);
    
    double price() const override;
    
    void setFaceValue(double val);
    double getFaceValue() const;
};