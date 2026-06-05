# Hangman 🎮️

A game🕹️ of hangman written in C++

## Concepts and design decisions

### string and string_view

* **std::string** allocates memory to own and modify its own copy of text, whereas **std::string_view** is a lightweight, read-only window that simply points to text owned by another string without copying it.  
* Use **std::string** when a function needs to modify the text, return a brand-new string, or store the data long-term where it must outlive the original source. Use **std::string_view** for read-only function parameters, text-parsing loops, or string-slicing operations where you want to eliminate the performance cost of copying memory.
