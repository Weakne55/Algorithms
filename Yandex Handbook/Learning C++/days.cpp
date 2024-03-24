#include <iostream>

int main(){
    int m,y;
    std::cin >> m >> y;
    if (y % 4 != 0 && m == 2){
        std::cout << "28";
    }
    else if (y % 100 != 0 && m == 2){
        std::cout << "29";
    }
    else if (y % 400 != 0 && m == 2){
        std::cout << "28";
    }
    else if (m == 2){
        std::cout << "29";
    }
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        std::cout << "31";
    }
    else{
        std::cout << "30";
    }
    return 0;
}