#ifndef CURRENCYEXCHANGE_H
#define CURRENCYEXCHANGE_H

#include "CreditCard.h" // base class header

class CurrencyExchange : public CreditCard {

private:

    double egpToUsdRate;
    double egpToEurRate;
    double egpToCadRate;

public:

    CurrencyExchange(double egpToUsd, double egpToEur, double egpToCad)
    : egpToUsdRate(egpToUsd), egpToEurRate(egpToEur), egpToCadRate(egpToCad){}


    double egpToUsd(double amountEGP);


    double egpToEur(double amountEGP);

    double egpToCad(double amountEGP);


    void exchangeAndAddToBalance(double amountEGP, double exchangeRate);

};

#endif
