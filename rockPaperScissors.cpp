#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";

class RockPaperScissors {
private:
    int userScore = 0;
    int compScore = 0;
    int roundCount = 1;
    
    int lastUserMove = -1; 
    
    // This matrix stores history
    // It tracks how often the user plays a specific move AFTER their last move.
    int transitions[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    string moveName(int move) {
        if (move == 0) return "Rock";
        if (move == 1) return "Paper";
        return "Scissors";
    }

    int getPredictedMove() {
        // If it's the first round, we play randomly
        if (lastUserMove == -1) {
            return rand() % 3; 
        }

        int likelyUserMove = 0;
        int maxFrequency = -1;

        // Now we think
        for (int i = 0; i < 3; i++) {
            if (transitions[lastUserMove][i] > maxFrequency) {
                maxFrequency = transitions[lastUserMove][i];
                likelyUserMove = i;
            }
        }

        if (maxFrequency == 0) {
            return rand() % 3;
        }

        // Note that
        // Rock (0) is beaten by Paper (1)
        // Paper (1) is beaten by Scissors (2)
        // Scissors (2) is beaten by Rock (0)
        return (likelyUserMove + 1) % 3;
    }

public:
    RockPaperScissors() {
        srand(time(0)); // We seed the random number generator once
    }

    void play() {
        cout << CYAN << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << " Welcome to Rock-Paper-Scissors \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RESET;
        
        cout << "Do you want to play? (1 for Yes, 0 for No): ";
        string choice;
        getline(cin, choice);

        if (choice != "1") {
            cout << YELLOW << "Bye! :) Please do come again when you feel like playing.\n" << RESET;
            return;
        }

        cout << "How many rounds? (Enter 0 for endless mode): ";
        getline(cin, choice);
        int totalRounds;
        
        // Error Handling
        try {
            totalRounds = stoi(choice);
        } catch (...) {
            cout << RED << "Please try being serious. Good Bye.\n" << RESET;
            return;
        }

        bool endless = (totalRounds <= 0);

        while (endless || totalRounds > 0) {
            cout << CYAN << "\n--- Round " << roundCount << " ---" << RESET << endl;
            cout << "Choose your move:\n";
            cout << "[1] Rock  [2] Paper  [3] Scissors  [4] Quit\n> ";
            
            getline(cin, choice);
            if (choice == "4") break;
            if (choice != "1" && choice != "2" && choice != "3") {
                cout << RED << "Invalid move. Please try being serious.\n" << RESET;
                return;
            }

            // We convert input "1", "2", "3" to 0, 1, 2 for easier array indexing
            int userMove = stoi(choice) - 1; 
            int compMove = getPredictedMove();

            // Update our prediction history matrix
            if (lastUserMove != -1) {
                transitions[lastUserMove][userMove]++;
            }
            lastUserMove = userMove;

            cout << "\nYou played: " << GREEN << moveName(userMove) << RESET << endl;
            cout << "I played:   " << YELLOW << moveName(compMove) << RESET << endl;

            // Determine winner
            if (userMove == compMove) {
                cout << CYAN << "Haha, it's a TIE!" << RESET << endl;
            } else if ((userMove == 0 && compMove == 2) || (userMove == 1 && compMove == 0) || (userMove == 2 && compMove == 1)) {
                cout << GREEN << "You won this round!" << RESET << endl;
                userScore++;
            } else {
                cout << RED << "I won this round :)" << RESET << endl;
                compScore++;
            }

            cout << "Score -> You: " << userScore << " | Me: " << compScore << "\n";

            if (!endless) totalRounds--;
            roundCount++;
        }

        // Final Results
        cout << CYAN << "\n====================================\n" << RESET;
        cout << "FINAL SCORE - You: " << userScore << " | Me: " << compScore << endl;
        
        if (userScore > compScore) {
            cout << GREEN << "Congrats! You won the game!\n" << RESET;
        } else if (compScore > userScore) {
            cout << RED << "I won! Thanks for playing.\n" << RESET;
        } else {
            cout << YELLOW << "DRAW! GG.\n" << RESET;
        }
        
        cout << CYAN << "====================================\n" << RESET;
        cout << "Good Bye!\n";
    }
};

int main() {
    RockPaperScissors game;
    game.play();
    return 0;
}
