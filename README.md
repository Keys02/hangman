# Hangman 🎮️

A game🕹️ of hangman written in C++

## Concepts and design decisions

### std::string and std::string_view

* **std::string** allocates memory to own and modify its own copy of text, whereas **std::string_view** is a lightweight, read-only window that simply points to text owned by another string without copying it.  
* Use **std::string** when a function needs to modify the text, return a brand-new string, or store the data long-term where it must outlive the original source. Use **std::string_view** for read-only function parameters, text-parsing loops, or string-slicing operations where you want to eliminate the performance cost of copying memory.

### std::array and std::vector

* An elements cannot be added to an **std::array** at runtime, therefore it's mostly prefered over **std::vector** when the number of element in a list at compile-time is known.
