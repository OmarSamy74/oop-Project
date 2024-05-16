#include "Customer.h"

using namespace std;

void Customer::First_time() {
    setName();
    setAge();
    setGender();
    setID();
    cout << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << "\n\n";
}

void Customer::setName() {
    cin.ignore(); // clear input buffer
    cout << "Enter your full name: ";
    getline(cin, name);
}

void Customer::setAge() {
    cout << "Enter your age: ";
    cin >> age;
}

void Customer::setGender() {
    cout << "M - Male\nF - Female\nYour choice: ";
    cin >> gender;

    gender = toupper(gender); // convert input into uppercase

    if (gender != 'M' && gender != 'F') {
        throw invalid_argument("Invalid input! Please try again.");
        setGender();
    }
}

void Customer::setID() {
    default_random_engine generator(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> distribution(1, 99999);

    ID = distribution(generator);
    cout << "\nYour unique ID is: " << ID << endl;
}

void Customer::addLoyaltyPoints(int numPoints) {
    default_random_engine generator(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> distribution(1, 99999);

    int points = distribution(generator);
    loyalty_points.push_back(points);
}

void Customer::PersonalInfo_edit() {
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
        cout << "Invalid input\n";
    }
}

// Accessor functions
std::string Customer::getName() const {
    return name;
}

short Customer::getAge() const {
    return age;
}

char Customer::getGender() const {
    return gender;
}

double Customer::getID() const {
    return ID;
}

const std::vector<double>& Customer::getLoyaltyPoints() const {
    return loyalty_points;
}
