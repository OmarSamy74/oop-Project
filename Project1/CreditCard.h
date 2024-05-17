#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include <iomanip>
using namespace std;

class CreditCard {

private:

    void showBalance() const;
    void deposit();
    void withdraw();

protected:

    double balance;

public:

    CreditCard(); // Constructor with no arguments

    void menu();

};

#endif // CREDITCARD_H
