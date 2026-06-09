#include <vector>
#include <string>

namespace Hangman {
    class WordGenerator {
        public:
            static std::string generateWord();

        private:
            static std::vector<std::string> words;
    };
}