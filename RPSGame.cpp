

//Rock, Paper, and Scissors Game
#include "RPSGame.h"

using namespace std;

// Constructor for the Rock, Paper, and Scissor Game
RPSGame::RPSGame() : Game("Rock, Paper, and Scissor Game"), num_of_attempts(0) {
    initializeGame(); // Initialize the game settings
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
}

// Additional game initialization logic can be added here if needed
void RPSGame::initializeGame()
{
    // No specific initialization for this game yet // I couldn't find any initalize
}

// Start function for the Rock, Paper, and Scissor Game
void RPSGame::start()
{
    Game::start(); // Call the base class start function
    cout << "\nWelcome to the Rock, Paper, and Scissor Game!" << endl;
}

// End function for the Rock, Paper, and Scissor Game
void RPSGame::end()
{
    Game::score(num_of_attempts); // Display the final score
}

// Rules function for the Rock, Paper, and Scissor Game
void RPSGame::rules()
{
    Game::rules(); // Display the base class rules
    cout << endl;
    cout << "The game is playe between the computer and you." << endl;
    cout << "You have to choose one of the three options (rock, paper, or scissor) to beat!" << endl;
    cout << "The computer will generate a random option for you." << endl << endl;
    cout << " Note: " << endl;
    cout << " rock    : Rock" << endl << " paper   : Paper" << endl << " scissor : Scissor" << endl << endl;
    cout << endl;
}

// Play function for the Rock, Paper, and Scissor Game
void RPSGame::play(const string& dif_level)
{
    player = new Player("Player"); // Create a new player
    Game::play(dif_level); // Call the base class play function
    rules(); // Display game-specific rules
    start(); // Start the game

    char play_again;
    int check = 0;
    do {
        int number = rand() % 100;

        // Determine computer's tool based on a random number
        if (number < 33) {
            computerTool = "rock";
        }
        else if (number > 66) {
            computerTool = "scissor";
        }
        else {
            computerTool = "paper";
        }

        cout << "\nEnter your choice: ";
        cin >> playerTool;
        cout << endl;

        convertingToLower(); // Convert uppercase letters to lowercase

        while (check == 0) {
            // Validate user input
            if (playerTool == "rock" || playerTool == "paper" || playerTool == "scissor") {
                check = 1;

                int conclusion = selectingTool(playerTool, computerTool);
                displayResults(conclusion);

                cout << "\nDo you want to Play Again?" << endl;

                cout << "Note: Press 'x' to exit! Press Anything to continue: ";
                cin >> play_again;
                cout << endl;

                // Add a visual separator for better readability
                for (int i = 0; i < 50; i++) {
                    cout << "-";
                }
                cout << endl;
            }
            else {
                check = 0;
                cout << "Invalid choice. Please try again." << endl;
                cout << "Enter your choice (rock, paper, or scissor): ";
                cin >> playerTool;
                cout << endl;
            }
        }

        check = 0;
        end(); // Call the end function to display the final score

    } while (play_again != 'x' || play_again != 'X');
}

// Display game results based on the outcome
void RPSGame::displayResults(int result) {

    // Displaying the outcome of the game based on the result
    if (result == 1) {
        cout << "You won! Hurray" << endl;
        num_of_attempts--; // Decreasing the number of attempts for a win
    }
    else if (result == -1) {
        cout << "You lose! Bad Luck" << endl;
        num_of_attempts++; // Increasing the number of attempts for a loss
    }
    else {
        cout << "Woah! That's a Tie!" << endl; // Displaying a tie outcome
    }

    // Displaying the tools used by the computer and the player
    cout << "\nThe computer's tool was: " << computerTool << endl;
    cout << "Your tool was: " << playerTool << endl;
}

// Function to determine the outcome of the game based on player and computer tools
int RPSGame::selectingTool(string p, string c) {
    if (p == c) {
        return 0; // Indicates a tie
    }
    // Checking different tool combinations to determine the outcome
    if (p == "rock" && c == "paper") {
        return -1; // Indicates player loses
    }
    else if (p == "scissor" && c == "paper") {
        return 1; // Indicates player wins
    }
    else if (p == "paper" && c == "rock") {
        return 1; // Indicates player wins
    }
    else if (p == "scissor" && c == "rock") {
        return -1; // Indicates player loses
    }
    else if (p == "rock" && c == "scissor") {
        return 1; // Indicates player wins
    }
    else if (p == "paper" && c == "scissor") {
        return -1; // Indicates player loses
    }
}

// Function to convert input tools to lowercase
void RPSGame::convertingToLower()
{
    // Converting the player and computer tools to lowercase for case-insensitive comparison
    for (char& a : playerTool) {
        a = tolower(a);
    }
    for (char& b : computerTool) {
        b = tolower(b);
    }
}
