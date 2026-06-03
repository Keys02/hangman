#include <vector>
#include <string>

namespace Hangman {
    class WordGenerator {
        std::vector<std::string> words = {
            "abstraction", "polymorphism", "inheritance", "encapsulation",
            "template", "overloading", "generic"
        };

        public:
            std::string generateWord();
    };
}