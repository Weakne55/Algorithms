#include <iostream>

int main(){
    int y;
    std::cin >> y;
    if (y % 4 != 0){
        std::cout << "NO";
    }
    else if (y % 100 != 0){
        std::cout << "YES";
    }
    else if (y % 400 != 0){
        std::cout << "NO";
    }
    else{
        std::cout << "YES";
    }
    return 0;
}