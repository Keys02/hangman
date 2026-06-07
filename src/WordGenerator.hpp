#include <vector>
#include <string>

namespace Hangman {
    class WordGenerator {
        static std::vector<std::string> words;

        public:
            static std::string generateWord();
    };
}