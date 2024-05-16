#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cctype>

using namespace std;

class Customer {
private:
    string name;
    short age;
    char gender;
    vector<double> loyalty_points;
    double ID;

public:
    void First_time() {
        setName();
        setAge();
        setGender();
        setID();
        cout << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << "\n\n";
    }

    void setName() {
        cin.ignore();  // clear input buffer
        cout << "Enter your full name: ";
        getline(cin, name);
    }

    void setAge() {
        cout << "Enter your age: ";
        cin >> age;
    }

    void setGender() {
        cout << "M - Male\nF - Female\nYour choice: ";
        cin >> gender;
        gender = toupper(gender);  // convert input into uppercase

        if (gender != 'M' && gender != 'F') {
            throw invalid_argument("Invalid input! Please try again.");
        }
    }

    void setID() {
        default_random_engine generator(static_cast<unsigned int>(time(0)));
        uniform_int_distribution<unsigned int> distribution(1, 99999);
        ID = distribution(generator);
        cout << "\nYour unique ID is: " << ID << endl;
    }

    void addLoyaltyPoints(int numPoints) {
        default_random_engine generator(static_cast<unsigned int>(time(0)));
        uniform_int_distribution<unsigned int> distribution(1, 99999);
        int points = distribution(generator);
        loyalty_points.push_back(points);
    }

    void PersonalInfo_edit() {
        int change;
        cout << "What would you like to change?\n"
            << "1. Name\n2. Gender\n3. Age\n";
        cin >> change;

        switch (change) {
        case 1:
            setName();
            break;
        case 2:
            setGender();
            break;
        case 3:
            setAge();
            break;
        default:
            cout << "Invalid input";
        }
    }

    string getName() const {
        return name;
    }

    short getAge() const {
        return age;
    }

    char getGender() const {
        return gender;
    }

    double getID() const {
        return ID;
    }

    const vector<double>& getLoyaltyPoints() const {
        return loyalty_points;
    }
};

#endif
