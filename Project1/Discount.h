#pragma once
#include <vector>
using namespace std;

class Discount {
public:
    // Constructor with base discount rate argument
    Discount(double baseRate);

    // Setter and getter methods for base discount rate
    void setBaseDiscountRate(double rate);
    double getBaseDiscountRate() const;

    // Method to set loyalty points levels
    void setLoyaltyPointsLevels(const std::vector<int>& levels);

    // Method to calculate discount based on loyalty points
    double calculateDiscount(int loyaltyPoints);

private:
    double baseDiscountRate; // Member variable to store the base discount rate
    std::vector<int> loyaltyPointsLevels;
};
