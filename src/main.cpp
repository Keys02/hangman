#include "Game.cpp"

using namespace Hangman;

int main() {
    std::size_t main_menu_option = Game::showMainMenu();

    // if start game is selected from the main menu
    if (main_menu_option == 1) {
        Game::start();
    }
    return 0;
}