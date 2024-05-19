#include "Event.h"

Event::Event() {
    // Constructor implementation here if needed
}

void Event::rush() {
    cout << "Successfully stated being in a rush.\n Extra fees will be applied.\n";
    // add code to increase total order price by 5%
}

void Event::clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Event::startup() {
    cout << "Welcome to Baladina!\nOur services:\n"
        "1. Credit card services.\n"
        "2. Let us get to know you.\n"
        "3. Edit personal information\n"
        "4. Order.\n"
        "Please enter the number of your desired service or 'q' to quit: ";
}

void Event::save_data(vector<Customer> customers) {
    // Implementation for saving data to file
}

void Event::waiting() {
    do {
        cout << "\nEnter your choice:\n\n"
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
                    for (char &c : recommendation) {
                        c = toupper(c);
                    }
                    if (recommendation == "DONE") 
                        break;
                }
                cout << "Thank you for your recommendation.\n";
                menu.addRecommendation(recommendation);
                break;
            case 5:
                cout << "Thanks for visiting!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);
}
