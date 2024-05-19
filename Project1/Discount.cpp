#include "Discount.h"

Discount::Discount(double baseRate) : baseDiscountRate(baseRate) {}

// Setter method sets the base discount rate
void Discount::setBaseDiscountRate(double rate) {
    baseDiscountRate = rate;
}

// Getter method returns the base discount rate
double Discount::getBaseDiscountRate() const {
    return baseDiscountRate;
}
void Discount::setLoyaltyPointsLevels(const vector<int>& levels) {
    loyaltyPointsLevels = levels;
}