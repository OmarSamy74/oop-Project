#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restaurant {
private:
    string name;
    string address;
    string cuisine;
    int capacity;
    vector<int> freeTablesNumbers;
    vector<string> freeTablesNames;

public:
    Restaurant(const string& name, const string& address, const string& cuisine, int capacity);

    void setName(const string& nName);
    void setAddress(const string& nAddress);
    void setCapacity(int nCapacity);

    string getName() const;
    string getAddress() const;
    string getCuisine() const;
    int getCapacity() const;

    void addFreeTable(int tableNumber, const string& tableName);
    void displayFreeTables() const;
};