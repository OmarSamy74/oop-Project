#include "GuessGame.h"
#include <iomanip> // for setw and setprecision

using namespace std;

Guess_Game::Guess_Game()
    : score(0), questionIndex(0), optionIndex(0), size(NUM_QUESTIONS) {
}

Guess_Game::Guess_Game(string filename)
    : score(0), questionIndex(0), optionIndex(0), size(NUM_QUESTIONS) {
    loadQuestionsFromFile(filename);
}

void Guess_Game::loadQuestionsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        if (line.empty()) {
            // Skip empty lines
            continue;
        }

        if (line.front() == '#') {
            // line is a question
            questions[questionIndex++] = line.substr(1);
            optionIndex = 0;
        }
        else if (isalpha(line.front())) {
            // line is an option
            options[questionIndex - 1][optionIndex++] = line;
        }
        else if (line.front() == '*') {
            // line contains the answer key
            answerKey[questionIndex - 1] = toupper(line[1]);
        }
    }
    file.close();
}

void Guess_Game::startQuiz() {
    for (int i = 0; i < size; i++) {
        cout << "*\n";
        cout << questions[i] << '\n';
        cout << "*\n";

        for (int j = 0; j < NUM_OPTIONS; j++) {
            cout << options[i][j] << '\n';
        }

        cout << "Your answer (A/B/C/D): ";
        cin >> guess;
        guess = toupper(guess);

        // Input validation
        while (guess != 'A' && guess != 'B' && guess != 'C' && guess != 'D') {
            cout << "Invalid input. Please enter A, B, C, or D: ";
            cin >> guess;
            guess = toupper(guess);
        }

        if (guess == answerKey[i]) {
            cout << "CORRECT\n";
            score++;
        }
        else {
            cout << "WRONG!\n";
            cout << "Answer: " << answerKey[i] << '\n';
        }
    }

    cout << "*\n"
        << "*           RESULTS           *\n"
        << "*\n"
        << "CORRECT GUESSES: " << setw(3) << score << '\n'
        << "# of QUESTIONS:  " << setw(3) << size << '\n'
        << "SCORE:           " << setw(6) << fixed << setprecision(2) << (score / (double)size) * 100 << "%\n";
}

void Guess_Game::playQuiz() {
    startQuiz();
}
