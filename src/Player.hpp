#pragma once
#include <cstddef>
#include <set>
namespace Hangman {
    class Player {
        public:
            std::size_t getIncorrectGuesses() const;
            void incrIncorrectGuesses();
            void addCorrectLetterGuessed(char letter);
            std::set<char> getAllCorrectGuessedLetters() const;
        private:
            std::size_t incorrectGuesses = 0;
            std::set<char> guessedCorrectLetters;
    };
}