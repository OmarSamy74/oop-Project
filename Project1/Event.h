#ifndef EVENT_H
#define EVENT_H

#include "Customer.h"
#include "GuessGame.h"
#include "Menu.h"
#include "TicTacToe.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

void rush();

void clearTerminal();

void startup();

void save_data(const std::vector<Customer>& customers);

void waiting();

#endif // EVENT_H
