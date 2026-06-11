#include <iostream>
#include "Menu.hpp"
#include "Art.hpp"
#include "Player.cpp"
#include "WordGenerator.cpp"
#include "algorithm"

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

void Menu::printGameOver() {
    std::cout << R"(
  _____          __  __ ______    ______      ________ _____  
 / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
| |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
| | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
| |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
 \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\
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
    //===============================================
    //                Gameplay Logic
    //===============================================
    Player player_one;
    std::string generated_word = WordGenerator::generateWord();

    std::cout << "\n\n";

    while (player_one.getIncorrectGuesses() <= 6) {
        std::string word_guess_status = "";

        // game over after six incorrect guesses
        if (player_one.getIncorrectGuesses() == 6) {
            std::cout << getArts(player_one.getIncorrectGuesses()) << '\n';

            // display the correct word after six incorrect guesses
            for (const char& word_letter : generated_word) {
                std::cout << word_letter << " ";
            }
            std::cout << "\n\n";

            std::cout << "The rope was faster than your guesses" << '\n';
            std::cout << "Better luck next time!" << '\n';
            printGameOver();
            std::cout << '\n';
            break;
        }

        std::cout << getArts(player_one.getIncorrectGuesses()) << '\n';
        std::cout << "Guess the letters in the word\n\n";


        // check if no correct letter has been guessed
        if (player_one.getAllCorrectGuessedLetters().empty()) {
            for (std::size_t i = 1; i <= generated_word.length(); ++i) {
                word_guess_status += "_ ";
            }
        } else {
            // re-render word status using correct letters previously guessed
            for (const char& word_letter : generated_word) {
                bool word_letter_found = false ;
                
                for (const char& correct_guessed_letter : player_one.getAllCorrectGuessedLetters()) {
                    if (word_letter == correct_guessed_letter) {
                        word_guess_status += word_letter;
                        word_guess_status += ' ';
                        word_letter_found = true;
                    }
                }

                if (!word_letter_found)
                    word_guess_status += "_ ";
            }

        }

        std::cout << word_guess_status << "\n\n";

        // check if all the letters has been guessed
        if (std::none_of(word_guess_status.begin(), word_guess_status.end(), [](char c) { return c == '_'; })) {
            std::cout << getWinningArt() << "\n";
            std::cout << "Congratulation, you have found all the letters\n";
            std::cout << word_guess_status << '\n';
            break;
        }

        char letter = Menu::wordLettersGuessInput();
        
        bool found_one_letter = false;

        for (const char& lettr : generated_word) {
            if (lettr == letter) {
                found_one_letter = true;
                player_one.addCorrectLetterGuessed(letter);
            } 
        }

        if (!found_one_letter) {
            player_one.incrIncorrectGuesses();
        }
    }
}