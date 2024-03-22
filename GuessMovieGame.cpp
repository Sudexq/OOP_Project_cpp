

#include "GuessMovieGame.h"
#include<iostream>

GuessMovieGame::GuessMovieGame() : Game("Guess the Movie"), num_of_attempts(0) {
    initialize_m_lists();
    srand(static_cast<unsigned int>(time(nullptr)));
}

//vector, i found it from google and it is so useful for my code as a future engineer i decided using this system
void GuessMovieGame::initialize_m_lists() {
    // Initialize MY movie lists as EASY AND MEDIUM AND HARD
    easy_m = { "Oppenheimer", "Wonka", "Grinch" ,"Inception","Interstellar", "Spencer"};
    medium_m = { "The Batman", "Mission Impossible", "Citizen Kane" , "Star Wars", "Harry Potter", "Shutter Island"};
    hard_m = { "Raiders of the Lost Ark", "The Dark Knight", "The Truman Show" , "Lord of the rings", "The Shawshank Redemption"};
}

void GuessMovieGame::start() {
    // Choose a movie based on difficulty
    Game::start();

    //DIFFICULTY MODE
    while (true) {
        //selecting difficulty mode
        cout << "Select difficulty (easy, medium, hard): ";

        //CHOOSING difficulty mode
        cin >> difficulty;
        cout << "" << endl;
        //EASY
        if (difficulty == "easy" || difficulty == "Easy" || difficulty == "EASY") {
            //easy movies which are only a word, we are choosing with getrandomMovie() func
            selectingMovie = getRandomMovie(easy_m); //getrandommovie is choosing mode with vector. inside of the method is the mode of the movie
            break;
        }
        //MEDIUM
        else if (difficulty == "medium" || difficulty == "Medium" || difficulty == "MEDIUM") {
            //medium movies which are have two words, we are choosing with getrandomMovie() func
            selectingMovie = getRandomMovie(medium_m);//getrandommovie is choosing mode with vector. inside of the method is the mode of the movie
            break;
        }
        //HARD
        else if (difficulty == "hard" || difficulty == "Hard" || difficulty == "HARD") {
            //hard movies which have got 3 words ,we are choosing with getrandomMovie() func
            selectingMovie = getRandomMovie(hard_m);//getrandommovie is choosing mode with vector. inside of the method is the mode of the movie
            break;
        }
        else {
            cout << "you entered wrong thing try again..\n" << endl;
            continue;
        }
    }
    // i am trying to hiding movie name with * 
    hidisibleMovie = selectingMovie;
    //a is the letters which are inside of the movie name
    for (char& a : hidisibleMovie) {
        //i found isalpha() from https://cplusplus.com/reference/cctype/isalpha/ 
        if (isalpha(a)) {
            a = '*';
        }
    }
    //starting game after the selecting mode
    cout << "" << endl;
    cout << "\nGame is starting! Can you guess the movie?\n" << endl;
    //just displaying our invisible movie
    display_invisible_movie();
}
//end of the game func
void GuessMovieGame::end() {
    cout << endl;
    cout << "The movie was: " << selectingMovie << endl;
}

// Function to display game rules
void GuessMovieGame::rules() {
    Game::rules();
    // Adding specific rules for the Guess Movie game
    cout << "Guess the hidden movie name.\nYou can guess letters or the whole movie name." << endl;
    cout << endl;
}

// Function to start and manage the gameplay
void GuessMovieGame::play(const string& dif_level) {
    player = new Player("Player"); // Creating a new player instance
    this->difficulty = dif_level; // Setting game difficulty level
    Game::play(dif_level); // Inheriting and initializing base game
    rules(); // Displaying game rules
    start(); // Starting the game

    // Main game loop
    while (!checkGuessMovie()) {
        char u_choice;

        // Displaying user options
        cout << "\nChoose an option:\n1. Guess a letter\n2. Guess the movie name\n";
        cin >> u_choice;

     
        if (u_choice == '1') {
            char theLetter;
            cout << "Enter a letter: ";
            cin >> theLetter;
           
            if (checkLetter(theLetter)) {
                cout << "Correct guess! ";
                display_invisible_movie();
            }
            else {
                cout << "Incorrect guess. ";
            }
            num_of_attempts++;
        }
        else if (u_choice == '2') {
            string theMovie;
            cout << "Enter the movie name: ";
            cin.ignore(); // Clear the newline character from previous input
            getline(cin, theMovie);

            if (theMovie == selectingMovie) {
                cout << "Congratulations! You guessed it right." << endl;
                Game::score(num_of_attempts);
                break;
            }
            else {
                cout << "Incorrect guess. ";
            }
            num_of_attempts++;
        }
        else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
        display_invisible_movie();
    }

    // Ending the game
    end();
}

// Function to get a random movie from the provided list
string GuessMovieGame::getRandomMovie(const vector<string>& movieList) {
    int randomIndex = rand() % movieList.size();
    return movieList[randomIndex];
}

//this func just displaying Hidden Movies 
void GuessMovieGame::display_invisible_movie() const {
    cout << "Hidden Movie: " << hidisibleMovie << endl;
}

// Function to check if a guessed letter is correct and update the hidden movie accordingly
bool GuessMovieGame::checkLetter(char letter) {
    bool letterFound = false;
    for (size_t i = 0; i < selectingMovie.size(); i++) {
        if (tolower(selectingMovie[i]) == tolower(letter)) {
            hidisibleMovie[i] = selectingMovie[i];
            letterFound = true;
        }
    }
    return letterFound;
}

// Function to check if the entire movie name has been guessed
bool GuessMovieGame::checkGuessMovie() {
    // Converting both movie names to lowercase for case-insensitive comparison
    for (char& c : selectingMovie){
        c = tolower(c);
    }
    return selectingMovie == hidisibleMovie;
}
