#include <iostream>
#include "Menu.hpp"
#include "Art.hpp"
#include "Player.cpp"
#include "WordGenerator.cpp"

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
    std::cout << "2. Each wrong guess adds a part to the hangman.\n";
    std::cout << "3. You lose after 6 mistakes.\n";
    std::cout << "Good luck!!! \n\n";
    
    std::cout << "Press Enter to return to main menu\n";
    std::cin.ignore();
    std::cin.get();
}

std::size_t Menu::showMainMenu() {
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
            return Menu::showMainMenu();
        case 3:
            return 3;
        default:
            std::cout << "\nInvalid choice. Try again!!\n";
            return Menu::showMainMenu();
    }
}

char Menu::wordLettersGuessInput() {
    char guess_char = 0;
    std::cin >> guess_char;
    return guess_char;
}

void Menu::showHiddenWord() {
    Player player_one;
    std::string generated_word = WordGenerator::generateWord();

    while (player_one.getIncorrectGuesses() <= 6) {
        std::cout << getArts(player_one.getIncorrectGuesses()) << '\n';
        std::cout << "Guess the letters in the word\n\n";
        for (std::size_t i = 1; i <= generated_word.length(); ++i) {
            std::cout << "_ ";
        }
        std::cout << "\n\n";
        char letter = Menu::wordLettersGuessInput();
        
        std::string word_guess_status = "";
        bool found_one_letter = false;

        for (char& lettr : generated_word) {
            if (lettr == letter) {
                word_guess_status += lettr;
                word_guess_status += " ";
                found_one_letter = true;
            } else {
                word_guess_status += "_ ";
            }
        }

        if (!found_one_letter) {
            player_one.incrIncorrectGuesses();
        }

        std::cout << word_guess_status << '\n';
    }
}
