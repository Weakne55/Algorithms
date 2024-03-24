#include <string>
#include <iostream>

 
int main() {
    std::string one = "C++ is a general-purpose programming language with a bias towards systems programming that\n";
    std::string three = "  - is a better C\n";
    std::string four = "  - supports data abstraction\n";
    std::string five = "  - supports object-oriented programming\n";
    std::string six = "  - supports generic programming.\n";
    std::cout << one << three << four << five << six;
}