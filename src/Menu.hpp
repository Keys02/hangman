#pragma once
#include <cstddef>

namespace Hangman {
    class Menu {
        public:
            static std::size_t showMainMenu();
            static void showHiddenWord(std::size_t word_length);
            static char wordLettersGuessInput();
        private:
            static void printTitle();
            static void showRules();
    };
}