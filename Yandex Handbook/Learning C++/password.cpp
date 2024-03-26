#include <iostream>

int main(){
    std::string password;
    std::cin >> password;
    int small = 0;
    int big = 0;
    int num = 0;
    int etc = 0;

    if (password.size() < 8 || password.size() > 14){
        std::cout << "NO";
    }
    else {
        for (int elem : password){
            if ( elem < 33 || elem > 126){
                std::cout << "NO";
                break;
            }
            else{
                if ( std::islower(elem)){
                    small = 1;
                }
                else if ( std::isupper(elem)){
                    big = 1;
                }
                else if ( std::isdigit(elem)){
                    num = 1;
                }
                else{
                    etc = 1;
                }
            }
        }
        int check = small+big+num+etc;
        if (check >= 3){
            std::cout << "YES";
        }
        else{
            std::cout << "NO";
        }
    }
}