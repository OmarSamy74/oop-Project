#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>

class Restaurant {
private:
    std::string name;
    std::string address;
    std::string cuisine;
    int capacity;
    std::vector<int> freeTablesNumbers;
    std::vector<std::string> freeTablesNames;

public:
    Restaurant(const std::string& name, const std::string& address, const std::string& cuisine, int capacity);

    void setName(const std::string& nName);
    void setAddress(const std::string& nAddress);
    void setCapacity(int nCapacity);

    std::string getName() const;
    std::string getAddress() const;
    std::string getCuisine() const;
    int getCapacity() const;

    void addFreeTable(int tableNumber, const std::string& tableName);
    void displayFreeTables() const;
};

#endif // RESTAURANT_H
