#pragma once
#include <cstddef>
namespace Hangman {
    class Player {
        public:
            std::size_t getIncorrectGuesses() const;
            void setIncorrectGuesses();
        private:
            std::size_t incorrectGuesses = 0;
    };
}