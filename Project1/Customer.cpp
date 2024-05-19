#include "Customer.h"

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
    nextID= 0;
    if (nextID <= 100000) {
        ID = nextID++;
    } else {
        cerr << "Error: No more available IDs.\n";
        ID = 0;
    }
    cout << "\nYour unique ID is: " << ID << endl;
}

void Customer::addLoyaltyPoints(int numPoints) {
    default_random_engine generator(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> distribution(1, 100);

    int points = distribution(generator);
    loyalty_points.push_back(points);
}

void Customer::PersonalInfo_edit() {
    int change;

    cout << "What would you like to change?\n"
        << "1. Name\n2. Gender\n3. Age\n4.Exit";
    cin >> change;

    while (true){
        
        switch (change) {
        case 1:
            setName();
            
        case 2:
            setGender();
            
        case 3:
            setAge();
            
        case 4:
            cout<< "Exiting...";
            break;
        default:
            cout << "Invalid input\n";
        }
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
