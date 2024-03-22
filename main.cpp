
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include"RPSGame.h"
#include "FindSynonymGame.h"
#include "Game.h"
#include "GuessMovieGame.h"

using namespace std;
void gameDisplay();

int main() {

    // Function prototype for displaying the game menu
    gameDisplay();
    return 0;
}

// Function to display the main menu and handle user input
void gameDisplay()
{
    // Main loop for displaying the menu repeatedly
    while (true) {

        // Displaying the main menu options
        cout << "\nMain Menu:" << endl;
        cout << "1. Find the Synonym" << endl;
        cout << "2. Guess Movie" << endl;
        cout << "3. Rock, Paper, and Scissor" << endl;
        cout << "4. Exit" << endl;

        int option;
        cout << "Enter your choice: ";
        cin >> option;

        Game* game = nullptr; // Pointer to the base Game class

        // Switch statement to create an instance of the selected game
        switch (option) {
        case 1:
            game = new FindSynonymGame(); // Creating an instance of FindSynonymGame
            break;
        case 2:
            game = new GuessMovieGame(); // Creating an instance of GuessMovieGame
            break;
        case 3:
            game = new RPSGame(); // Creating an instance of RPSGame
            break;
        case 4:
            exit(0); // Exit the program if the user chooses option 4
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            continue;  // Go back to the start of the loop if the choice is invalid
        }

        // Call the play function of the selected game
        game->play("");

        // Deallocate memory for the game instance
        delete game;
    }
}

