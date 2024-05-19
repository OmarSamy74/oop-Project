#pragma once
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

    CreditCard(); // default constructor

    void menu();

};