#include "Player.hpp"

using namespace hangman;

int Player::getIncorrectGuesses() const {
    return Player::incorrectGuesses;
}

void Player::setIncorrectGuesses() {
    Player::incorrectGuesses++;
}