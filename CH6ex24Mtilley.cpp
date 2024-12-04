#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>
#include <fstream>  
#include <sstream>  

using namespace std;

int getComputerChoice() {
    return rand() % 3 + 1;  
}

string choiceToString(int choice) {
    if (choice == 1) return "rock";
    if (choice == 2) return "paper";
    return "scissors";
}

int getUserChoice() {
    string userChoice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors): ";
        cin >> userChoice;

        if (userChoice == "rock") return 1;
        if (userChoice == "paper") return 2;
        if (userChoice == "scissors") return 3;

        cout << "Invalid input! Please enter 'rock', 'paper', or 'scissors'." << endl;
    }
}

string determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }
    if ((userChoice == 1 && computerChoice == 3) ||  
        (userChoice == 2 && computerChoice == 1) ||  
        (userChoice == 3 && computerChoice == 2)) {  
        return "user";
    }
    return "computer";
}

void displayPreviousSessions(const string& filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "No previous sessions found." << endl;
        return;
    }

    cout << "Previous Sessions:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void saveSession(const string& filename, const string& userChoice, const string& computerChoice, const string& winner) {
    ofstream file(filename, ios::app);  

    if (file.is_open()) {
        file << "User chose: " << userChoice << ", Computer chose: " << computerChoice << ", Winner: " << winner << endl;
        file.close();
    }
    else {
        cout << "Error opening file!" << endl;
    }
}

int main() {
    srand(time(0));  

    string filename = "game_sessions.txt";  
    int userChoice, computerChoice;
    string winner;
    string userChoiceStr, computerChoiceStr;

    while (true) {
        cout << "\nRock, Paper, Scissors Game Menu:" << endl;
        cout << "1. Start a new session" << endl;
        cout << "2. Display previous sessions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        int menuChoice;
        cin >> menuChoice;

        if (menuChoice == 1) {
            computerChoice = getComputerChoice();
            userChoice = getUserChoice();

            userChoiceStr = choiceToString(userChoice);
            computerChoiceStr = choiceToString(computerChoice);

            winner = determineWinner(userChoice, computerChoice);

            cout << "Computer chose: " << computerChoiceStr << endl;
            cout << "You chose: " << userChoiceStr << endl;
            if (winner == "tie") {
                cout << "It's a tie! Let's play again." << endl;
            }
            else {
                cout << "The winner is: " << (winner == "user" ? "You" : "Computer") << "!" << endl;
            }

            saveSession(filename, userChoiceStr, computerChoiceStr, winner);
        }
        else if (menuChoice == 2) {
            displayPreviousSessions(filename);
        }
        else if (menuChoice == 3) {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid option! Please select 1, 2, or 3." << endl;
        }
    }

    return 0;
}
