#include <iostream>
#include <algorithm>
#include <memory>
#include "Game.hpp"
#include "Art.hpp"
#include "Player.cpp"
#include "WordGenerator.cpp"

using namespace Hangman;

void Game::printTitle() {
    std::cout << R"(
 _   _                                         
| | | | __ _ _ __   __ _ _ __ ___   __ _ _ __  
| |_| |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
|  _  | (_| | | | | (_| | | | | | | (_| | | | |
|_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                   |___/                        
    )";
}

void Game::printGameOver() {
    std::cout << R"(
  _____          __  __ ______    ______      ________ _____  
 / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
| |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
| | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
| |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
 \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\
    )";
}

void Game::showRules() {
    std::cout << "\n --- RULES ---\n";
    std::cout << "1. Guess the hidden word.\n";
    std::cout << "2. Each wrong guess adds a part to the hangman.\n";
    std::cout << "3. You lose after 6 mistakes.\n";
    std::cout << "Good luck!!! \n\n";
    
    std::cout << "Press Enter to return to main menu\n";
    std::cin.ignore();
    std::cin.get();
}

std::size_t Game::showMainMenu() {
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
            return Game::showMainMenu();
        case 3:
            return 3;
        default:
            std::cout << "\nInvalid choice. Try again!!\n";
            return Game::showMainMenu();
    }
}

char Game::wordLettersGuessInput() {
    char guess_char = 0;
    std::cin >> guess_char;
    return guess_char;
}

void Game::start() {
    //===============================================
    //                Gameplay Logic
    //===============================================
    std::unique_ptr<Player> player = std::make_unique<Player>();
    std::string generated_word = WordGenerator::generateWord();

    std::cout << "\n";

    while (player->getIncorrectGuesses() <= 6) {
        std::string word_guess_status = "";

        // game over after six incorrect guesses
        if (player->getIncorrectGuesses() == 6) {
            std::cout << getArts(player->getIncorrectGuesses()) << '\n';

            // display the correct word after six incorrect guesses
            for (const char& word_letter : generated_word) {
                std::cout << word_letter << " ";
            }
            std::cout << "\n\n";

            std::cout << "The rope was faster than your guesses" << '\n';
            std::cout << "Better luck next time!" << '\n';
            printGameOver();
            player.reset();
            std::cout << '\n';
            std::cout << "Press Enter to return to main menu\n";
            std::cin.ignore();
            std::cin.get();

            // replay game again
            std::system("clear");
            size_t main_menu_option = Game::showMainMenu();
            if (main_menu_option == 1) {
                Game::start();
            }
        }

        std::cout << getArts(player->getIncorrectGuesses()) << '\n';
        std::cout << "Guess the letters in the word\n\n";


        // check if no correct letter has been guessed
        if (player->getAllCorrectGuessedLetters().empty()) {
            for (std::size_t i = 1; i <= generated_word.length(); ++i) {
                word_guess_status += "_ ";
            }
        } else {
            // re-render word status using correct letters previously guessed
            for (const char& word_letter : generated_word) {
                bool word_letter_found = false ;
                
                for (const char& correct_guessed_letter : player->getAllCorrectGuessedLetters()) {
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
            std::cout << getWinningArt() << "\n"; // display winning art
            std::cout << word_guess_status << "\n\n";
            player.reset();
            std::cout << "Congratulation, you have found all the letters\n\n";
            std::cout << "Press Enter to return to main menu\n";
            std::cin.ignore();
            std::cin.get();

            // replay game again
            std::system("clear");
            size_t main_menu_option = Game::showMainMenu();
            if (main_menu_option == 1) {
                Game::start();
            }
        }

        // take player letter input
        char letter = Game::wordLettersGuessInput();
        
        bool found_one_letter = false;

        for (const char& lettr : generated_word) {
            if (lettr == letter) {
                found_one_letter = true;
                // add correct letter to the guessed letter tracker to re-render the word status
                player->addCorrectLetterGuessed(letter);
            } 
        }

        if (!found_one_letter) {
            player->incrIncorrectGuesses();
        }
    }
}