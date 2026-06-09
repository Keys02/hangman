#include <iostream>
#include "Menu.cpp"

using namespace Hangman;

int main() {
    std::size_t main_menu_option = Menu::showMainMenu();

    // if start game is selected from the main menu
    if (main_menu_option == 1) {
        Menu::showHiddenWord();
    }
    return 0;
}