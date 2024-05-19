#pragma once
#include "Customer.h"
#include "GuessGame.h"
#include "Menu.h"
#include "TicTacToe.h"

class Event{

    private:
    
    int choice;
    Guess_Game player;
    TicTacToe game;
    Menu menu;
    string recommendation;

    public:

    Event();
    void rush();
    void clearTerminal();
    void startup();
    void save_data(vector<Customer>customers);
    void waiting();

};