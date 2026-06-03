#include <iostream>
#include "Words.cpp"

using namespace Hangman;

int main() {
    WordGenerator word_generator; 
    std::cout << word_generator.generateWord() << '\n';
    return 0;
}