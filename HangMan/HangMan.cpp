//Hangman
//The classic game of hangman
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<ctime>
#include<cctype> // cctype. It's part of the standard library and it
                 //includes functions for converting characters to uppercase
using namespace std;
int main() {
    //setup
    const int MAX_WRONG = 8;

    vector<string> words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(words.begin(), words.end(), std::default_random_engine(seed));
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;
        char guess;
        cout << "\n\nEnter your guess:";
        cin >> guess;
        guess = toupper(guess);
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";

            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the world.\n";
            ++wrong;
        }
    }
    //shut down
    if (wrong == MAX_WRONG)
    {
        cout << "\nyou've been hanged!";
    }
    else
    {
        cout << "\nYou guessed it!";
    }
    cout << "\nThe word was " << THE_WORD << endl;
    return 0;
}




