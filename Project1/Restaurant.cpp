#include "Restaurant.h"

Restaurant::Restaurant(const std::string& name, const std::string& address, const std::string& cuisine, int capacity)
    : name(name), address(address), cuisine(cuisine), capacity(capacity), freeTablesNumbers(), freeTablesNames() {
}

void Restaurant::setName(const std::string& nName) {
    name = nName;
}

void Restaurant::setAddress(const std::string& nAddress) {
    address = nAddress;
}

void Restaurant::setCapacity(int nCapacity) {
    capacity = nCapacity;
}

std::string Restaurant::getName() const {
    return name;
}

std::string Restaurant::getAddress() const {
    return address;
}

std::string Restaurant::getCuisine() const {
    return cuisine;
}

int Restaurant::getCapacity() const {
    return capacity;
}

void Restaurant::addFreeTable(int tableNumber, const std::string& tableName) {
    freeTablesNumbers.push_back(tableNumber);
    freeTablesNames.push_back(tableName);
}

void Restaurant::displayFreeTables() const {
    std::cout << "Free Tables:\n";
    for (size_t i = 0; i < freeTablesNumbers.size(); ++i) {
        std::cout << "Table " << freeTablesNumbers[i] << " - " << freeTablesNames[i] << "\n";
    }
}
