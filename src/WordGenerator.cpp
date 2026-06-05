#include "WordGenerator.hpp"
#include <ctime>
#include <random>

// seed the generator using the system's hardware entropy source
std::random_device rd; 

// initialize the engine with the seed
std::mt19937 gen(rd()); 

using namespace Hangman;

std::vector<std::string> WordGenerator::words = {
    "abstraction", "polymorphism", "inheritance", "encapsulation",
    "template", "overloading", "generic"
};

std::string WordGenerator::generateWord() {
    std::uniform_int_distribution<std::size_t> dist(0, WordGenerator::words.size() - 1);
    std::size_t word_pos = dist(gen);
    return WordGenerator::words[word_pos];
}