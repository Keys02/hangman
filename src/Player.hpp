#pragma once
#include <cstddef>
#include <set>
#include <string>
#include <vector>
namespace Hangman {
    class Player {
        public:
            std::size_t getIncorrectGuesses() const;
            void incrIncorrectGuesses();
            void addCorrectLetterGuessed(char letter);
            std::set<char> getAllCorrectGuessedLetters() const;
            void updateKeyboardState(const char& input_char);
            void printKeyboard();
        private:
            std::vector<std::string> keyboard {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
            std::vector<std::string>& getKeyboardState();
            std::size_t incorrectGuesses = 0;
            std::set<char> guessedCorrectLetters;
    };
}