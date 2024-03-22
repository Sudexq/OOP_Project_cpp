

#ifndef RPS_GAME_H
#define RPS_GAME_H


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>  // For changing to lowercase
#include <string>
#include "Game.h"

using namespace std;

class RPSGame : public Game {
public:
    RPSGame(); // Constructor

    // Public member functions
    int selectingTool(string p, string c);
    void start() override;
    void end() override;
    void rules() override;
    void play(const std::string& dif_level) override;

private:
    void convertingToLower(); // Helper function to convert strings to lowercase
    void initializeGame();    // Helper function to initialize the game
    string computerTool;      // Stores the computer's tool (rock, paper, or scissors)
    string playerTool;        // Stores the player's tool (rock, paper, or scissors)
    void displayResults(int result); // Helper function to display game results
    int num_of_attempts = 0;  // Number of attempts in the game
};

#endif // RPS_GAME_H

