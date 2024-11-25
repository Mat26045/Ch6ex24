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
    cout << "Choose one: rock, paper, or scissors (or type 'exit' to quit): ";
    while (true) {
        cin >> playerChoice;
        if (playerChoice == "rock" || playerChoice == "paper" || playerChoice == "scissors" || playerChoice == "exit") {
            return playerChoice;
        }
        else {
            cout << "Invalid choice. Please choose again: rock, paper, or scissors (or type 'exit' to quit): ";
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
    string playerName;
    int playerWins = 0, computerWins = 0, draws = 0;

    srand(static_cast<unsigned int>(time(0)));

    cout << "Enter your name: ";
    cin >> playerName;

    while (true) {
        int computerChoiceNumber = getComputerChoice();
        string computerChoice = choiceToString(computerChoiceNumber);

        string playerChoice = getPlayerChoice();

        if (playerChoice == "exit") {
            cout << "Exiting the game. Thank you for playing!" << endl;
            break;
        }

        cout << playerName << " chose: " << playerChoice << endl;
        cout << "Computer chose: " << computerChoice << endl;

        string winner = determineWinner(playerChoice, computerChoice);

        if (winner == "draw") {
            cout << "It's a draw! Let's play again.\n" << endl;
            draws++;
        }
        else if (winner == "player") {
            cout << "Congratulations, " << playerName << "! You win this round.\n" << endl;
            playerWins++;
        }
        else {
            cout << "Sorry, the computer wins this round.\n" << endl;
            computerWins++;
        }

        cout << "\nCurrent score:\n";
        cout << playerName << ": " << playerWins << " wins\n";
        cout << "Computer: " << computerWins << " wins\n";
        cout << "Draws: " << draws << "\n\n";
    }
}

int main() {
    playGame();
    return 0;
}
