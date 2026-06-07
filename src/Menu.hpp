#pragma once
#include <cstddef>

namespace Hangman {
    class Menu {
        public:
            static int showMainMenu();
            static void showHiddenWord(std::size_t word_length);
        private:
            static void printTitle();
            static void showRules();
    };
}