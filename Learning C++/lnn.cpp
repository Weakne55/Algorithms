#include <iostream>
#include <cmath>

int main(){
    double answer, minus;
    int i,j,n;
    std::cin >> n;

    answer = 0.0;
    minus = 1.0;
    
    j = 1;
    while (j <= n){

        for (i = 0; i <= j; ++i){
            minus = minus * (-1.0);
        }
        answer += minus/j;
        minus = 1.0;
        ++j;
    }
    std::cout << answer;
    return 0;
}