#pragma once
#include <string_view>
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

    inline std::string_view getArts(std::size_t incorrectGuesses) {
        if (incorrectGuesses > 6)  incorrectGuesses = 6;
        return arts[incorrectGuesses];
    }
}