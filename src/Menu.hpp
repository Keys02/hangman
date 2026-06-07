#pragma once

namespace Hangman {
    class Menu {
        public:
            static int showMainMenu();
        private:
            static void printTitle();
            static void showRules();
    };
}