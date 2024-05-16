#include "CreditCard.h"
using namespace std;

CreditCard::CreditCard() : balance(0) {}

void CreditCard::menu() {
    int choice;
    do {
        cout << "\n"
            << "Enter your choice:\n"
            << "\n"
            << "1. Show Balance\n"
            << "2. Deposit Money\n"
            << "3. Withdraw Money\n"
            << "4. Exit\n";
        cin >> choice;

        cin.clear();
        fflush(stdin);

        switch (choice) {
        case 1:
            showBalance();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            cout << "Thanks for visiting!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);
}

void CreditCard::showBalance() const {
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << '\n';
}

void CreditCard::deposit() {
    double amount = 0;
    cout << "Enter amount to be deposited: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        showBalance();
    }
    else {
        cout << "That's not a valid amount:\n";
    }
}

void CreditCard::withdraw() {
    double amount = 0;
    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient funds\n";
    }
    else if (amount < 0) {
        cout << "That's not a valid amount\n";
    }
    else {
        balance -= amount;
        showBalance();
    }
}
