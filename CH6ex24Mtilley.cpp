#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int getComputerChoice() {
    return rand() % 3 + 1; 
}

string choiceToString(int choice) {
    if (choice == 1) return "rock";
    else if (choice == 2) return "paper";
    else return "scissors";
}

string getPlayerChoice() {
    string playerChoice;
    cout << "Choose one: rock, paper, or scissors: ";
    while (true) {
        cin >> playerChoice;
        if (playerChoice == "rock" || playerChoice == "paper" || playerChoice == "scissors") {
            return playerChoice;
        }
        else {
            cout << "Invalid choice. Please choose again: rock, paper, or scissors: ";
        }
    }
}

string determineWinner(string playerChoice, string computerChoice) {
    if (playerChoice == computerChoice) {
        return "draw";
    }
    else if ((playerChoice == "rock" && computerChoice == "scissors") ||
        (playerChoice == "scissors" && computerChoice == "paper") ||
        (playerChoice == "paper" && computerChoice == "rock")) {
        return "player";
    }
    else {
        return "computer";
    }
}

void playGame() {
    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        int computerChoiceNumber = getComputerChoice();
        string computerChoice = choiceToString(computerChoiceNumber);

        string playerChoice = getPlayerChoice();

        cout << "Player chose: " << playerChoice << endl;
        cout << "Computer chose: " << computerChoice << endl;

        string winner = determineWinner(playerChoice, computerChoice);

        if (winner == "draw") {
            cout << "It's a draw! Let's play again." << endl << endl;
        }
        else if (winner == "player") {
            cout << "Congratulations! You win!" << endl;
            break;
        }
        else {
            cout << "Sorry, the computer wins. Try again." << endl;
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}
