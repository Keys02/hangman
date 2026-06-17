#pragma once
#include <cstddef>

namespace Hangman {
    class Game {
        public:
            static std::size_t showMainMenu();
            static void start();
            static char wordLettersGuessInput();
        private:
            static void printTitle();
            static void showRules();
            static void printGameOver();
            static void clearScreen();
    };
}