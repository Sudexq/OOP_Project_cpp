

#ifndef GUESSMOVIEGAME_H
#define GUESSMOVIEGAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>//to changing lowercase
#include "Game.h"

using namespace std;

class GuessMovieGame : public Game{
public:
    GuessMovieGame(); // Constructor

    void start() override;
    void end() override;
    void rules() override;
    void play(const string& dif_level) override;
    

private:
    string difficulty;
    void initialize_m_lists();
    string getRandomMovie(const vector<string>& movieList); //vector, i found it from google and it is so useful for my code as a future engineer i decided using this system
    void display_invisible_movie() const; //displaying hidden movie
    bool checkLetter(char letter); //is letter in movie?
    bool checkGuessMovie() ; //is guessed movie correct?

    vector<string> easy_m; //easy movies
    vector<string> medium_m; //medium movies
    vector<string> hard_m; //hard movies

    string selectingMovie; //which is choosed movie from computer
    string hidisibleMovie; //hidden movie
    int num_of_attempts; //number of attempts
};

#endif // GUESSMOVIEGAME_H


