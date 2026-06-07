#include "Player.hpp"

using namespace hangman;

std::size_t Player::getIncorrectGuesses() const {
    return Player::incorrectGuesses;
}

void Player::setIncorrectGuesses() {
    Player::incorrectGuesses++;
}