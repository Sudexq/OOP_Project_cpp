//sudenur Tilla
//2200007172

#include "Player.h"



void Player::info_player(string name_of_game)
{
	cout << "\nenter user name: ";
	cin >> username;
	cout << "";
	cout << "name of the game: " << name_of_game << endl;
	cout << "Your score: " << score << " for now" << endl;
	
}

