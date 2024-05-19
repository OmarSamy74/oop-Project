#include "Menu.h"

Menu::Menu() : name(""), dishes({}) {}

Menu::Menu(const string& name, const vector<Dish>& dishes) : name(name), dishes(dishes) {}

Menu::Menu(const string& filename) : name(""), dishes({}) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string name;
        double price;

        // Split line into name and price
        size_t last_space = line.find_last_of(" ");
        if (last_space == string::npos) {
            continue; // Invalid format
        }

        name = line.substr(0, last_space);
        try {
            price = stod(line.substr(last_space + 1));
        }
        catch (const invalid_argument&) {
            continue; // Invalid price format
        }

        dishes.push_back(Dish{name, price});
    }

    file.close();
}

char Menu::getDelivery() {
    cout << "Do you want home delivery?\nPress 'N' for dine-in and 'Y' for delivery\n";
    cin >> delivery;

    if (delivery == 'N' || delivery == 'n') {
        return 'N';
    }
    else if (delivery == 'Y' || delivery == 'y') {
        return 'Y';
    }
    else {
        cout << "Invalid input\n";
        return getDelivery();
    }
}

vector<string> Menu::getDishes() const {
    return dishes;
}

void Menu::displayMenu() const {
    cout << "Menu:\n";
    for (const auto& dish : dishes) {
        cout << dish << "\n";
    }
}

void Menu::addRecommendation(const string& recommendation) {
    customerMenu.push_back(recommendation);
}

void Menu::displayCustomerMenu() const {
    cout << "Customer recommendations:\n";
    for (const auto& dish : customerMenu) {
        cout << dish << "\n";
    }
}

void Menu::placeOrder() {
    cout << "Our current menu: \n";
    displayMenu();

    cout << "Our customer recommendations: \n";
    displayCustomerMenu();

    cout << "Enter your order (one item per line, type 'done' to finish):\n";

    while (true) {
        cin.ignore(); // Clear the input buffer
        getline(cin, item);
        transform(item.begin(), item.end(), item.begin(), ::toupper);

        if (item == "DONE")
            break;
        order.push_back(item);
    }

    cout << "Placing Order:\n";

    for (const auto& item : order) {
        auto it = find(dishes.begin(), dishes.end(), item);
        if (it != dishes.end()) {
            cout << "Ordered: " << *it << "\n";
        }
        else {
            cout << "Item not found: " << item << "\n";
        }
    }

    if (delivery == 'Y' || delivery == 'y') {
        cout << "While waiting, what do you want to do?";
        waiting(); // Assuming waiting() is defined elsewhere
    }

    cout << "Your order will be delivered to:\n";
    address->displayAddress();
    cout << "Your order has been placed.\n"
        << "It will reach you within sixty minutes\n"
        << "Thank you for your order.\n";
}

string DeliveryAddress::getRecipientName() const {
    return recipientName;
}

string DeliveryAddress::getStreetAddress() const {
    return streetAddress;
}

string DeliveryAddress::getCity() const {
    return city;
}

void DeliveryAddress::setRecipientName(const string& name) {
    recipientName = name;
}

void DeliveryAddress::setStreetAddress(const string& address) {
    streetAddress = address;
}

void DeliveryAddress::setCity(const string& cityName) {
    city = cityName;
}

void DeliveryAddress::displayAddress() const {
    cout << "Recipient Name: " << recipientName << "\n";
    cout << "Street Address: " << streetAddress << "\n";
    cout << "City: " << city << "\n";
}

void DeliveryAddress::inputAddress() {
    cout << "Enter the recipient's name: ";
    cin.ignore();
    getline(cin, recipientName);

    cout << "Enter the street address: ";
    getline(cin, streetAddress);

    cout << "Enter the city: ";
    getline(cin, city);
}
