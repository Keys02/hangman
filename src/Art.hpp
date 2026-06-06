#include <string_view>
#pragma once
#include <array>

namespace Hangman {
    inline constexpr std::array<std::string_view, 7> arts = {
    R"#(
        +---+
        |   |
        |    
        |    
        |    
        |
        ========= 
    )#",

    R"#(
        +---+
        |   |
        |   O
        |    
        |    
        |
        =========
    )#",
    R"#(
        +---+
        |   |
        |   O
        |   |
        |    
        |
        =========
    )#",

    R"#(
        +---+
        |   |
        |   O
        |  /|
        |    
        |
        =========
    )#",

    R"#(
        +---+
        |   |
        |   O
        |  /|\
        |    
        |
        =========
    )#",

    R"#(
        +---+
        |   |
        |   O
        |  /|\
        |  /
        |
        =========
    )#",

    R"#(
        +---+
        |   |
        |   O
        |  /|\
        |  / \
        |
        =========
    )#"
    };

    inline std::string_view getArts(int mistakes) {
        if (mistakes < 0) mistakes = 0;
        if (mistakes > 6)  mistakes = 6;
        return arts[mistakes];
    }
}