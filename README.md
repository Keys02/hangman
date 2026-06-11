# Hangman 🎮️

A game🕹️ of hangman written in C++

## Concepts and design decisions

### std::string and std::string_view

* **std::string** allocates memory to own and modify its own copy of text, whereas **std::string_view** is a lightweight, read-only window that simply points to text owned by another string without copying it.  
* Use **std::string** when a function needs to modify the text, return a brand-new string, or store the data long-term where it must outlive the original source. Use **std::string_view** for read-only function parameters, text-parsing loops, or string-slicing operations where you want to eliminate the performance cost of copying memory.

### std::array and std::vector

* An elements cannot be added to an **std::array** at runtime, therefore it's mostly prefered over **std::vector** when the number of element in a list at compile-time is known.

### Why we combine **constexpr** and **inline**
Before C++17, if you wanted to create a global constant in a header file to use across your entire project, you had a problem. If you just used **constexpr**:

```c++
// MyConstants.h
namespace Constants {
    constexpr double pi = 3.14159; 
}
```

If five different .cpp files included MyConstants.h, the compiler would create five separate copies of pi in memory.
By adding inline, you fix this completely:

```c++
// MyConstants.h (Modern C++17 Way)
namespace Constants {
    inline constexpr double pi = 3.14159; 
}
```

Now, no matter how many files include this header, the compiler guarantees there is exactly one pi shared globally, and its value is known at compile-time.
