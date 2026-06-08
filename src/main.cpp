#include <iostream>
#include "WordGenerator.cpp"
#include "Menu.cpp"

using namespace Hangman;

int main() {
    std::size_t gameStatus = Menu::showMainMenu();

    if (gameStatus == 1) {
        Menu::showHiddenWord();
    }
    return 0;
}