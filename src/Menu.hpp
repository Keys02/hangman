#pragma once
#include <cstddef>

namespace Hangman {
    class Menu {
        public:
            static std::size_t showMainMenu();
            static void showHiddenWord();
            static char wordLettersGuessInput();
        private:
            static void printTitle();
            static void showRules();
            static void printGameOver();
    };
}