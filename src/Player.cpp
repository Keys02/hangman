#include "Player.hpp"

using namespace Hangman;

std::size_t Player::getIncorrectGuesses() const {
    return Player::incorrectGuesses;
}

void Player::setIncorrectGuesses() {
    Player::incorrectGuesses++;
}