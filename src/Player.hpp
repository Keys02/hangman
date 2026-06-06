#pragma once
namespace hangman {
    class Player {
            int incorrectGuesses = 0;
        public:
            int getIncorrectGuesses() const;
            void setIncorrectGuesses();
    };
}