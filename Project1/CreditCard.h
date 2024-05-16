#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include <iomanip>

class CreditCard {
protected:
    double balance;

public:
    CreditCard(); // Constructor with no arguments

    void menu();

private:
    void showBalance() const;
    void deposit();
    void withdraw();
};

#endif // CREDITCARD_H
