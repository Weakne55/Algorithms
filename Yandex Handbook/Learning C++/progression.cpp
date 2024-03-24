#include <iostream>

 
int main() {
    unsigned long int n;
    std::cin >> n;
    unsigned long long q  = n * (n + 1) / 2;
    std::cout << q << "\n";
}
 
// 2 147 483 647 - int max
// 4 294 967 295 - unsigned int max
