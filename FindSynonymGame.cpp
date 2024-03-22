//sudenur Tilla
//2200007172

// FindSynonymGame.cpp
#include "FindSynonymGame.h"
using namespace std;

// Constructor: Constructor function of FindSynonymGame class
FindSynonymGame::FindSynonymGame() : Game("Find Synonym"), randomIndex(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
    initializeWordSynonyms(wordSynonyms, size);
}
// initializeWordSynonyms: Function that initializes the word pool.
//THESE ARE MY WORDS, I GAVE MY HOURS FOR THIS LIST
void FindSynonymGame::initializeWordSynonyms(WordSynonymPair wordSynonyms[], int& size) {

    size = 66;
    wordSynonyms[0] = { "beautiful", {"pretty", "lovely", "attractive", "gorgeous", "alluring"} };
    wordSynonyms[1] = { "bad", {"atrocious", "wrong", "immoral", "unpleasant", "unfortunate"} };
    wordSynonyms[2] = { "big", {"enormous", "huge", "immense", "large", "grand"} };
    wordSynonyms[3] = { "amazing", {"incredible", "unbelievable", "improbable", "fabulous", "wonderful"} };
    wordSynonyms[4] = { "answer", { "reply", "respond", "retort", "acknowledge"} };
    wordSynonyms[5] = { "angry", {"mad", "furious", "enraged"} };
    wordSynonyms[6] = { "calm", {"quiet", "peaceful", "mild", "tranquil"} };
    wordSynonyms[7] = { "crooked", {"bent", "twisted", "curved", "hooked", "zigzag"} };
    wordSynonyms[8] = { "do", {"accomplish", "achieve", "act", "complete", "execute"} };
    wordSynonyms[9] = { "describe", {"portray", "characterize", "narrate", "relate", "represent"} };
    wordSynonyms[10] = { "dangerous", {"savory", "appetizing", "luscious", "toothsome", "delightful"} };
    wordSynonyms[11] = { "eager", {"keen", "fervent", "enthusiastic", "involved", "intrested"} };
    wordSynonyms[12] = { "end", {"stop", "finish", "terminate", "conclude", "close"} };
    wordSynonyms[13] = { "explain", {"eloborate", "clarify", "interpret", "define", "illustrate"} };
    wordSynonyms[14] = { "famous", { "wellknown", "renowned", "famed", "celebrated" } };
    wordSynonyms[15] = { "copy", { "version", "reproduction", "replica", "clone" } };
        wordSynonyms[16] = { "fast", {"quick", "rapid", "swift", "agile", "brisk"} };
        wordSynonyms[17] = { "funny", {"humorous", "amusing", "comic", "silly", "laughable"} };
        wordSynonyms[18] = { "get", {"acquire", "obtain", "secure", "procure", "gain"} };
        wordSynonyms[19] = { "good", {"fine", "exceptional", "satisfying", "favorable", "acceptable"} };
        wordSynonyms[20] = { "great", {"awesome", "fantastic", "marvelous", "perfect", "admirable"} };
        wordSynonyms[21] = { "happy", {"pleased", "contented", "satisfied", "delighted", "cheerful"} };
        wordSynonyms[22] = { "hate", {"despise", "loathe", "detest", "dislike"} };
        wordSynonyms[23] = { "help", {"aid", "assist", "support", "encourage", "back"} };
        wordSynonyms[24] = { "important", {"necessary", "vital", "critical", "significant", "indispensable"} };
        wordSynonyms[25] = { "interesting", {"engaging", "inviting", "stimulating", "thought-provoking", "unusual"} };
        wordSynonyms[26] = { "job", {"occupation", "work", "career"} };
        wordSynonyms[27] = { "jungle", {"forest"} };
        wordSynonyms[28] = { "keep", {"control", "hold", "retain", "preserve", "maintain"} };
        wordSynonyms[29] = { "kill", {"slay", "execute", "assassinate", "murder", "destroy"} };
        wordSynonyms[30] = { "kind", {"helpful", "generous", "compassionate", "gentle"} };
        wordSynonyms[31] = { "lazy", {"idle", "inactive", "indolent", "slothful"} };
        wordSynonyms[32] = { "little", {"tiny", "small", "diminutive", "shrimp", "runt"} };
        wordSynonyms[33] = { "love", {"like", "admire", "care for", "adore"} };
        wordSynonyms[34] = { "make", {"produce", "create", "originate", "invent", "construct"} };
        wordSynonyms[35] = { "move", {"blow", "carry", "drift", "transport", "shift"} };
        wordSynonyms[36] = { "moody", {"temperamental", "changeable", "irritable"} };
        wordSynonyms[37] = { "naughty", {"headstrong", "impish", "mischievous", "playful"} };
        wordSynonyms[38] = { "neat", {"clean", "orderly", "tidy", "elegant", "precise"} };
        wordSynonyms[39] = { "new", {"fresh", "original", "modern", "current", "recent"} };
        wordSynonyms[40] = { "occur", {"take place", "happen", "arise", "materialize", "exist"} };
        wordSynonyms[41] = { "odd", {"strange", "queer", "weird"} };
        wordSynonyms[42] = { "old", {"aged", "ancient", "used", "mature"} };
        wordSynonyms[43] = { "part", {"portion", "piece", "share", "section", "fraction"} };
        wordSynonyms[44] = { "place", {"space", "area", "spot", "region", "residence"} };
        wordSynonyms[45] = { "popular", {"accepted", "famous", "fashionable", "favored", "trendy"} };
        wordSynonyms[46] = { "quiet", {"silent", "still", "soundless", "mute", "peaceful"} };
        wordSynonyms[47] = { "quite", {"fairly", "pretty", "largely", "thoroughly", "totally"} };
        wordSynonyms[48] = { "right", {"correct", "true", "accurate", "factual", "proper"} };
        wordSynonyms[49] = { "real", {"genuine", "true", "absolute", "evident", "actual"} };
        wordSynonyms[50] = { "reliable", {"dependable", "trustworthy", "safe", "steady"} };
        wordSynonyms[51] = { "show", {"display", "exhibit", "indicate", "reveal", "demonstrate"} };
        wordSynonyms[52] = { "story", {"tale", "myth", "legend", "fable", "narrative"} };
        wordSynonyms[53] = { "strange", {"odd", "peculiar", "weird", "unusual", "unfamiliar"} };
        wordSynonyms[54] = { "smart", {"intelligent", "clever", "brilliant", "bright"} };
        wordSynonyms[55] = { "trouble", {"distress", "anguish", "worry", "concern", "difficulty"} };
        wordSynonyms[56] = { "true", {"accurate", "right", "proper", "precise", "exact"} };
        wordSynonyms[57] = { "think", {"consider", "contemplate", "reflect", "ponder", "mull over"} };
        wordSynonyms[58] = { "unfortunate", {"unlucky", "damaging", "deplorable", "regrettable", "untoward"} };
        wordSynonyms[59] = { "ugly", {"awful", "grotesque", "hideous", "frightening", "shocking"} };
        wordSynonyms[60] = { "usually", {"commonly", "frequently", "generally", "mostly", "regularly"} };
        wordSynonyms[61] = { "uneasy", {"restless", "concerned", "nervous", "anxious"} };
        wordSynonyms[62] = { "very", {"extremely", "tremendously", "exceedingly", "vastly"} };
        wordSynonyms[63] = { "value", {"worth", "merit", "usefulness"} };
        wordSynonyms[64] = { "wrong", {"incorrect", "inaccurate", "mistaken", "improper", "untrue"} };
        wordSynonyms[65] = { "wonderful", {"awesome", "amazing", "excellent", "outstanding", "fantastic"} };
        wordSynonyms[66] = { "yearly", {"annually", "yearlong"} };
}


// Define the getRandomWord function in the FindSynonymGame class.
string FindSynonymGame::getRandomWord(const WordSynonymPair wordSynonyms[], int size) {
    int randomIndex = rand() % size;
    return wordSynonyms[randomIndex].word;
}


// getSynonymWord: Function that returns the correct synonym of a random word.
string FindSynonymGame::getSynonymWord(const WordSynonymPair wordSynonyms[], int size, const string& word) {
    // Get a random word to be the current word
    currentWord = getRandomWord(wordSynonyms, size);
    for (int i = 0; i < size; ++i) {
        // Search for the provided word in the list
        if (wordSynonyms[i].word == word) {
            int randomIndex = rand() % 5;  // Assuming each word has up to 5 synonyms
            // Return a randomly selected synonym for the provided word
            return wordSynonyms[i].synonyms[randomIndex];
        }
    }
    return "";  // Return an empty string if the word is not found
}
// start:Function that sets a random word and its correct synonym at the beginning of the game.
void FindSynonymGame::start() {
    cout << endl;
    Game::start();
    currentWord = getRandomWord(wordSynonyms, size); // Get a random word and its correct synonym
    correctSynonym = getSynonymWord(wordSynonyms, size, currentWord);

    cout << "Word: " << currentWord << endl;
}

// end: Function that prints the correct synonym and score at the end of the game.
void FindSynonymGame::end() {
    cout << "The synonym was: " << correctSynonym << endl;
    cout << endl;
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    Game::score(num_of_attempts);
}

// rules: Function that prints the game rules on the screen.
void FindSynonymGame::rules() {
    Game::rules();
    cout << "Find the synonym of the given word." << endl;
    cout << "And You have a maximum of 5 guesses." << endl;
}

// play: The function that starts the game, takes predictions from the user and prints the result on the screen.
void FindSynonymGame::play(const string& dif_level) {

    player = new Player("Player"); // Creates the player object
    Game::play(dif_level);
    rules(); // rules are cominggggg
    start(); // starts gameeeee


    // Use a loop to allow the user a certain number of attempts (in this case, 5 attempts).
    for (num_of_attempts = 0; num_of_attempts < 5; ++num_of_attempts) {
        // Declare a string variable to store the user's guess.
        string userGuess;

        // Prompt the user to enter their guess.
        cout << endl;
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Check if the user's guess matches the correct synonym.
        if (userGuess == correctSynonym) {
            // If the guess is correct, display a congratulatory message and exit the loop.
            cout << "Congratulations! You guessed it right." << endl;
            break;
        }
        else {
            // If the guess is incorrect, inform the user and continue to the next iteration.
            cout << "Incorrect guess." << endl;
        }
    }

    // The loop ends either when the user guesses correctly or when the maximum attempts (5) are reached.


    end(); // result is comingggggggg
}

