#pragma once
#include <cstddef>
#include <vector>
namespace Hangman {
    class Player {
        public:
            std::size_t getIncorrectGuesses() const;
            void incrIncorrectGuesses();
            void addCorrectLetterGuessed(char letter);
            std::vector<char> getAllCorrectGuessedLetters();
        private:
            std::size_t incorrectGuesses = 0;
            std::vector<char> guessedCorrectLetters;
    };
}