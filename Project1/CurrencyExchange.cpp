#include "CurrencyExchange.h" // base class header

class CurrencyExchange : public CreditCard {

private:

    double egpToUsdRate;
    double egpToEurRate;
    double egpToCadRate;

public:

    CurrencyExchange(double egpToUsd, double egpToEur, double egpToCad)
        : egpToUsdRate(egpToUsd), egpToEurRate(egpToEur), egpToCadRate(egpToCad) {}


    double egpToUsd(double amountEGP) const {
        return amountEGP * egpToUsdRate;
    }


    double egpToEur(double amountEGP) const {
        return amountEGP * egpToEurRate;
    }


    double egpToCad(double amountEGP) const {
        return amountEGP * egpToCadRate;
    }


    void exchangeAndAddToBalance(double amountEGP, double exchangeRate) 

    {
        double amountInTargetCurrency = amountEGP * exchangeRate;
        balance += amountInTargetCurrency;
    }
};