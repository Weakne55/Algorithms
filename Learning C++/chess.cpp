#include <iostream>
#include <cmath>


int main(){
    int x,y,a,b;
    std::cin >> x >> y >> a >> b;
    if (x == a || y == b){ 
        std::cout << "YES\n";
    } else if (std::abs(a - x) == std::abs(b - y)){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}