#include "Player.hpp"

using namespace Hangman;

std::size_t Player::getIncorrectGuesses() const {
    return incorrectGuesses;
}

void Player::incrIncorrectGuesses() {
    incorrectGuesses++;
}

void Player::addCorrectLetterGuessed(char letter) {
   guessedCorrectLetters.push_back(letter);
}