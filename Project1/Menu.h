#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class DeliveryAddress; // Forward declaration

class Menu {
private:
    std::vector<std::string> dishes;
    std::vector<std::string> customerMenu;
    char delivery;
    std::vector<std::string> order;
    std::string item;
    DeliveryAddress* address;

public:
    Menu(); // default constructor
    char getDelivery();

    std::vector<std::string> getDishes() const;

    void addDish(const std::string& dish);
    void displayMenu() const;

    void addRecommendation(const std::string& recommendation);
    void displayCustomerMenu() const;

    void placeOrder();
};

class DeliveryAddress {
private:
    std::string recipientName;
    std::string streetAddress;
    std::string city;

public:
    std::string getRecipientName() const;
    std::string getStreetAddress() const;
    std::string getCity() const;

    void setRecipientName(const std::string& name);
    void setStreetAddress(const std::string& address);
    void setCity(const std::string& cityName);

    void displayAddress() const;
    void inputAddress();

    friend class Menu;
};

void waiting();

#endif // MENU_H
