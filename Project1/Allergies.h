#pragma once
#include "Order.h"
using namespace std;

class Allergies : public Order {
private:
    string foodAllergies;

public:
    Allergies(const string& item, int quantity, const string& allergies);
    void setFoodAllergies(const string& allergies);
    string getFoodAllergies() const;
};
