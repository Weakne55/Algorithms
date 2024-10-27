#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::getline(std::cin, s);
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end()); 
    std::string s_rev = s;
    std::reverse(s_rev.begin(), s_rev.end());
    bool ans = (s == s_rev);

    if (ans) 
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    return 0;
}