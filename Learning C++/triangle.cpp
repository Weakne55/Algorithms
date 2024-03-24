#include <iostream>


int main(){
    int a,b,c;
    std::cin >> a >> b >> c;

    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }

    // Find the largest number
    int largest = a;
    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }

    int middle = a;
    if ((b < largest && b > smallest) || (b > largest && b < smallest)) {
        middle = b;
    } else if ((c < largest && c > smallest) || (c > largest && c < smallest)) {
        middle = c;
    }

    if (smallest + middle < largest){
        std::cout << "UNDEFINED\n";
    } else if ( smallest*smallest + middle*middle == largest*largest){
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}