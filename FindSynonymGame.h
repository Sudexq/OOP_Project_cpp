
//FindSynonymGame.h
//
// Game 1: Find the Synonym

// FINDSYNONYMGAME_H
#ifndef FINDSYNONYMGAME_H
#define FINDSYNONYMGAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"

using namespace std;

const int MAX_WORD_COUNT = 70;

// Structure to store a word and its synonyms
struct WordSynonymPair {
    string word;
    string synonyms[5];  // Each word can have up to 5 synonyms; you can adjust this number based on your needs
};

class FindSynonymGame : public Game {
public:
    WordSynonymPair wordSynonyms[MAX_WORD_COUNT]; // Array to store word-synonym pairs
    int size = 0; // Size of the array
    FindSynonymGame(); // Constructor
    void start() override; // Override start function
    void end() override; // Override end function
    void rules() override; // Override rules function
    void play(const string& dif_level) override; // Override play function

private:
    // Function to initialize the wordSynonyms array
    void initializeWordSynonyms(WordSynonymPair wordSynonyms[], int& size);
    // Function to get a random word from the wordSynonyms array
    string getRandomWord(const WordSynonymPair wordSynonyms[], int size);
    // Function to get the correct synonym for a given word
    string getSynonymWord(const WordSynonymPair wordSynonyms[], int size, const string& word);

    // Private member variables
    string currentWord;
    string correctSynonym;
    int randomIndex;
};

#endif // FINDSYNONYMGAME_H
