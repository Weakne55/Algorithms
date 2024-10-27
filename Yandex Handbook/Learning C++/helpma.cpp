#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::remove(s.begin(), s.end(), ' ');
    std::cout << s << s.size();
    return 0;
}