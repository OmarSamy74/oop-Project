#ifndef GUESSGAME_H
#define GUESSGAME_H

#include <iostream>
#include <string>
#include <fstream>
#include <cctype> // for toupper
#include <iomanip> // for setw and setprecision
using namespace std;

class Guess_Game {

private:

    static const int NUM_QUESTIONS = 4;
    static const int NUM_OPTIONS = 4;

    string questions[NUM_QUESTIONS];
    string options[NUM_QUESTIONS][NUM_OPTIONS];
    char answerKey[NUM_QUESTIONS];

    int score;
    string line;

    int questionIndex;
    int optionIndex;

    char guess;
    int size;

    // file opening
    void loadQuestionsFromFile(const string& filename);

    void startQuiz();

public:
    // default constructor
    Guess_Game();

    // constructor
    Guess_Game(string filename);

    void playQuiz();
};

#endif // GUESSGAME_H
