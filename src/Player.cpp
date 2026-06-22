#include "Player.hpp"
#include <iostream>
#include <cctype>
#include <string>

using namespace Hangman;

std::size_t Player::getIncorrectGuesses() const {
    return incorrectGuesses;
}

void Player::incrIncorrectGuesses() {
    incorrectGuesses++;
}

void Player::addCorrectLetterGuessed(char letter) {
   guessedCorrectLetters.insert(letter);
}

std::set<char> Player::getAllCorrectGuessedLetters() const {
    return guessedCorrectLetters;
}

void Player::updateKeyboardState(const char& input_char) {
    for (std::string& keyboard_letter : getKeyboardState()) {

        if (std::string (1, std::toupper(input_char)) == keyboard_letter) {
            keyboard_letter = "\033[2m" + keyboard_letter + "\033[0m"; // fade out the key
        }
    }
}

void Player::printKeyboard() {
    std::vector<std::string> keyboard_state = getKeyboardState();

    for (size_t i = 0; i < keyboard_state.size(); ++i) {
        if ((i + 1) % 13 == 0)
            std::cout << keyboard_state[i] << '\n';
        else
            std::cout << keyboard_state[i] << ' ';
    }

    std::cout << "\n";
}

std::vector<std::string>& Player::getKeyboardState() {
    return keyboard;
}