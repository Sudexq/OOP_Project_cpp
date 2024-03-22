
// Game.h

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Player class for managing player information
class Player
{
private:
	string username;
	string name_of_game;
	int score;

	friend class Game; //allow Game class to acsess private members

public:
	// Constructor to initialize player with a username
	Player(const string& username) : username(username), name_of_game(""), score(0) {}
	// Function to set additional information about the game for the player
	void info_player(string name_of_game);
};

// Abstract base class for defining common features of different games
class Game
{
protected:
	string name; // Name of the game
	Player *player; // Pointer to the player object
	int num_of_attempts; // Number of attempts made in the game

public:

	// Constructor to initialize the game with a name
	Game(const string& name) : name(name), player(nullptr), num_of_attempts(0) {}
	
	// Pure virtual functions to be implemented by derived game classes
	virtual void start() = 0;
	virtual void end() = 0;
	virtual void rules() = 0;
	virtual void play(const string& dif_level) = 0;
	// Virtual function to calculate and return the score, to be implemented by derived game classes
	virtual int score(int& score);

	// Virtual destructor to ensure proper destruction of derived game classes
	virtual ~Game();


};

#endif // GAME_H