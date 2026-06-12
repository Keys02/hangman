#include "WordGenerator.hpp"
#include <ctime>
#include <random>

// seed the generator using the system's hardware entropy source
std::random_device rd; 

// initialize the engine with the seed
std::mt19937 gen(rd()); 

using namespace Hangman;

std::vector<std::string> WordGenerator::words = {
    "apple", "banana", "orange", "grape", "mango",
    "watermelon", "pineapple", "strawberry", "cherry", "peach",

    "mountain", "river", "ocean", "forest", "desert",
    "island", "valley", "waterfall", "rainbow", "thunder",

    "animal", "tiger", "lion", "elephant", "giraffe",
    "zebra", "kangaroo", "dolphin", "penguin", "butterfly",

    "garden", "flower", "tree", "castle", "bridge",
    "village", "country", "city", "school", "library",

    "pencil", "notebook", "computer", "telephone", "camera",
    "mirror", "window", "blanket", "pillow", "backpack",

    "music", "guitar", "piano", "violin", "drummer",
    "artist", "painting", "theater", "dance", "singer",

    "journey", "adventure", "mystery", "treasure", "diamond",
    "freedom", "victory", "courage", "dream", "memory",

    "sunshine", "moonlight", "morning", "evening", "midnight",
    "holiday", "festival", "birthday", "friendship", "happiness",

    "chocolate", "sandwich", "coffee", "cookie", "icecream",
    "hamburger", "pancake", "noodles", "pizza", "popcorn"
};

std::string WordGenerator::generateWord() {
    std::uniform_int_distribution<std::size_t> dist(0, WordGenerator::words.size() - 1);
    std::size_t word_pos = dist(gen);
    return WordGenerator::words[word_pos];
}