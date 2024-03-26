#include <iostream>
#include <vector>


int main(){
    int n;
    int in;
    std::cin >> n;
    std::vector<int> place(n);
    for (size_t i = 0; i !=place.size(); ++i){
        std::cin >> in;
        place[in-1] = i+1;
    }
    for(size_t elem : place){
        std::cout << elem << " ";
    }
}