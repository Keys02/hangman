#include <iostream>
#include "Menu.hpp"

using namespace Hangman;

void Menu::printTitle() {
    std::cout << R"(
 _   _                                         
| | | | __ _ _ __   __ _ _ __ ___   __ _ _ __  
| |_| |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
|  _  | (_| | | | | (_| | | | | | | (_| | | | |
|_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                   |___/                        
    )";
}

void Menu::showRules() {
    std::cout << "\n --- RULES ---\n";
    std::cout << "1. Guess the hidden word.\n";
    std::cout << "2. Each wrong guess adds a part to the hangman.";
    std::cout << "3. You lose after 6 mistakes.";
    std::cout << "Goood luck!!! \n\n";
    
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int Menu::show() {
    printTitle();

    std::cout << "\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Rules\n";
    std::cout << "3. Quit\n";
    std::cout << "\nChoose an option: ";

    int choice;
    std::cin >> choice;

    switch(choice) {
        case 1:
            return 1;
        case 2:
            showRules();
            break;
        case 3:
            return 3;
        default:
            std::cerr << "Invalid choice. Try again\n\n"
    }
}