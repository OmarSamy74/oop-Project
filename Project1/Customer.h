#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cctype> // for toupper

class Customer {
private:
    std::string name;
    short age;
    char gender;
    std::vector<double> loyalty_points;
    double ID;

public:
    void First_time();

    void setName();
    void setAge();
    void setGender();
    void setID();

    void addLoyaltyPoints(int numPoints);

    void PersonalInfo_edit();

    // Accessor functions for private member variables 
    std::string getName() const;
    short getAge() const;
    char getGender() const;
    double getID() const;
    const std::vector<double>& getLoyaltyPoints() const;
};

#endif // CUSTOMER_H
