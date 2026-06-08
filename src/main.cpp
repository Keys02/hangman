#include <iostream>
#include "WordGenerator.cpp"
#include "Menu.cpp"

using namespace Hangman;

int main() {
    std::size_t gameStatus = Menu::showMainMenu();

    if (gameStatus == 1) {
        std::size_t word_length = WordGenerator::generateWord().length();
        Menu::showHiddenWord(word_length);
    }
    return 0;
}