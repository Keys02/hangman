#pragma once
#include <cstddef>
namespace hangman {
    class Player {
            std::size_t incorrectGuesses = 0;
        public:
            std::size_t getIncorrectGuesses() const;
            void setIncorrectGuesses();
    };
}