#include <iostream>
// Me
int main(){
    int n,k;
    std::cin >> n >> k;
    for (int i = 0; i <= k+n-1; ++i){

        if (i < n-1){
            std::cout<<"  ";
        }
        else if ( i >= n && (i-n+1) < 10){
            std::cout<<" " << i-n+1;
        } 
        else if ((i-n+1)>=10){
            std::cout<< i-n+1;
        }
        if ( i!=0 && (i%7 == 0 || i == k+n-1)){
            std::cout<<"\n";
        }
        else if (i-n+1 != 0){
            std::cout << " ";
        }
    }
    return 0;
} 
// Chat GPT
// #include <iostream>

// int main() {
//     int n, k;
//     std::cin >> n >> k;

//     // Определение количества пробелов перед первым числом
//     int spaces = (n - 1) * 3;

//     // Вывод пробелов в начале первой строки
//     for (int i = 0; i < spaces; ++i) {
//         std::cout << " ";
//     }

//     // Вывод календаря
//     for (int i = 1; i <= k; ++i) {
//         if (i < 10) {
//             std::cout << " "; // Вывод дополнительного пробела для чисел от 1 до 9
//         }
//         std::cout << i; // Вывод числа
//         if ((i + n - 1) % 7 == 0 || i == k) { // Переход на новую строку после каждой недели или в конце месяца
//             std::cout << std::endl;
//         } else {
//             std::cout << " "; // Вывод пробела между числами, кроме последнего числа в строке
//         }
//     }

//     return 0;
// }
