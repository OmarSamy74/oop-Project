#include "Allergies.h"

Allergies::Allergies(const string& item, int quantity, const string& allergies)
    : Order(item, quantity), foodAllergies(allergies) {}

void Allergies::setFoodAllergies(const string& allergies) {
    foodAllergies = allergies;
}

string Allergies::getFoodAllergies() const {
    return foodAllergies;
}
