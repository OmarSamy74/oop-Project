#ifndef CURRENCYEXCHANGE_H
#define CURRENCYEXCHANGE_H

#include "CreditCard.h" // Include the base class header

class CurrencyExchange : public CreditCard {
private:
    // Fixed exchange rates for different currencies
    double egpToUsdRate;
    double egpToEurRate;
    double egpToCadRate;

public:
    // Constructor with exchange rates
    CurrencyExchange(double egpToUsd, double egpToEur, double egpToCad)
        : egpToUsdRate(egpToUsd), egpToEurRate(egpToEur), egpToCadRate(egpToCad) {}

    // Function to exchange EGP to USD
    double egpToUsd(double amountEGP) const {
        return amountEGP * egpToUsdRate;
    }

    // Function to exchange EGP to EUR
    double egpToEur(double amountEGP) const {
        return amountEGP * egpToEurRate;
    }

    // Function to exchange EGP to CAD
    double egpToCad(double amountEGP) const {
        return amountEGP * egpToCadRate;
    }

    // Function to perform currency exchange and update balance
    void exchangeAndAddToBalance(double amountEGP, double exchangeRate) {
        double amountInTargetCurrency = amountEGP * exchangeRate;
        balance += amountInTargetCurrency;
    }
};

#endif // CURRENCYEXCHANGE_H
