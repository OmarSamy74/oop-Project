#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class DeliveryAddress; // Forward declaration

class Menu {

private:
    vector<string> dishes;
    vector<string> customerMenu;
    char delivery;
    vector<string> order;
    string item;
    DeliveryAddress* address;

public:
    Menu(); // default constructor
    char getDelivery();

    vector<string> getDishes() const;

    void addDish(const string& dish);
    void displayMenu() const;

    void addRecommendation(const string& recommendation);
    void displayCustomerMenu() const;

    void placeOrder();
};

class DeliveryAddress {
private:
    string recipientName;
    string streetAddress;
    string city;

public:
    string getRecipientName() const;
    string getStreetAddress() const;
    string getCity() const;

    void setRecipientName(const string& name);
    void setStreetAddress(const string& address);
    void setCity(const string& cityName);

    void displayAddress() const;
    void inputAddress();

    friend class Menu;
};

void waiting();

#endif
