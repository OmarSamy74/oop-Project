#include "Event.h"

using namespace std;

void rush() {
    cout << "Successfully started being in a rush.\nExtra fees will be applied.\n";
    // add code to increase total order price by 5%
}

void clearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void startup() {
    cout << "Welcome to Baladina!\nOur services:\n"
        << "1. Credit card services.\n"
        << "2. Let us get to know you.\n"
        << "3. Edit personal information\n"
        << "4. Order.\n"
        << "Please enter the number of your desired service or 'q' to quit: ";
}

void save_data(const vector<Customer>& customers) {
    ofstream outfile("customer_data.txt");
    if (!outfile) {
        cerr << "Error opening file for writing\n";
        return;
    }
    for (const Customer& customer : customers) {
        outfile << "Name: " << customer.getName() << endl;
        outfile << "Age: " << customer.getAge() << endl;
        outfile << "Gender: " << customer.getGender() << endl;
        outfile << "ID: " << customer.getID() << endl;

        const vector<double>& loyalty_points = customer.getLoyaltyPoints();
        if (!loyalty_points.empty()) {
            outfile << "Loyalty Points: ";
            for (double points : loyalty_points) {
                outfile << points << " ";
            }
            outfile << endl;
        }
        outfile << endl;
    }
    outfile.close();
}

void waiting() {
    int choice;
    Guess_Game player("questions.txt");
    TicTacToe game;
    Menu menu;
    string recommendation;

    do {
        cout << "\n"
            << "Enter your choice:\n"
            << "\n"
            << "1. Guess Game\n"
            << "2. Tic-Tac-Toe\n"
            << "3. Are you in a rush?\n"
            << "4. Any menu items recommendations?\n"
            << "5. Wait the remaining time.\n";

        cin >> choice;

        cin.clear();
        fflush(stdin);

        switch (choice) {
        case 1:
            player.playQuiz();
            break;
        case 2:
            game.playTicTacToe();
            break;
        case 3:
            rush();
            break;
        case 4:
            cout << "Enter your menu recommendation (one item per line, type 'done' to finish):\n";
            while (true) {
                cin >> recommendation;
                transform(recommendation.begin(), recommendation.end(), recommendation.begin(), ::toupper);
                if (recommendation == "DONE")
                    break;
                menu.addRecommendation(recommendation);
            }
            cout << "Thank you for your recommendation.\n";
            break;
        case 5:
            cout << "Thanks for visiting!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
}
