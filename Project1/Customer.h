#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cctype> // for toupper
using namespace std;

class Customer {
    
private:

    string name;
    short age;
    char gender;
    vector<double> loyalty_points;
    double ID;

public:

    void First_time();

    void setName();
    void setAge();
    void setGender();
    void setID();

    void addLoyaltyPoints(int numPoints);
    void PersonalInfo_edit();


    string getName() const;
    short getAge() const;
    char getGender() const;
    double getID() const;
    const vector<double>& getLoyaltyPoints() const;
};

#endif // CUSTOMER_H
