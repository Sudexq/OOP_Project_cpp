

#include "Game.h"

// The destructor of the Game class deletes the player object
Game::~Game() {
    delete player;
}

// The start method of the Game class asks the user if they want to play and starts the
void Game::start() {
    int a = 0;
    while (a ==! 1) {
        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl << endl;
        cout <<player->username << " are you Ready?\n" << endl;
        cout<< "DO YOU WANNA PLAY    ----> click 1 and enter!\nDON'T YOU WANNA PLAY ----> click something and you exit from whole game.." << endl;
        cout << "what is your decision " << player->username << " : ";
        cin >> a;
        
        switch (a) {
        case 1:
            cout << "\nOKAY! "<< player->username <<" then we continue\n";
            cout << "\nGAME IS STARTING!!!\n" << endl;
            for (int i = 0; i < 50; i++) {
                cout << "-";
            }
            cout << endl;
            break;
        default:
            cout << "you entered: " << a << endl;
            cout << "You should click 1 !!you exit from whole game!! please restart game" << endl;
            exit(0);
            break;
        }
    }
}
    
    
// Method to end the game
void Game::end() {
   cout << "Game ending..." << endl;
}
// Display the rules of the game
void Game::rules() {
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
   cout << endl;
   cout << "THE RULES" << endl;
   cout << endl;
}

// Method to start playing the game with a specified difficulty level
void Game::play(const string& dif_level) {
   cout << endl;
   for (int i = 0; i < 50; i++) {
        cout << "-";
   }
   cout << endl;
   // Display player information
   player->info_player(name);
   cout << endl;
}

// Calculate and display the player's score
int Game::score(int& score)
{
    int a = 26;
    a -= score;
    cout << endl;
    cout << player->username <<" your score: " << a << endl;
    return 0;
}

// Method to get player information for the game
void Player::info_player(string name_of_game)
{
    cout << "\nenter user name: ";
    cin >> username;
    cout << "";
    cout << "name of the game: " << name_of_game << endl;
    cout << "Your score: " << score << " for now" << endl;

}
