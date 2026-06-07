#include <iostream>
#include "WordGenerator.cpp"
#include "Menu.cpp"

using namespace Hangman;

int main() {
    int gameStatus = Menu::showMainMenu();

    if (gameStatus == 1) {
        WordGenerator word_generator; 
        std::cout << word_generator.generateWord() << '\n';
    }
    return 0;
}