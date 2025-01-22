#include <iostream>
#include <vector>

#include "selectionsort.cpp"
#include "mergesort.cpp"
#include "knappsack.cpp"
#include "greedy_knappsack.cpp"
#include "add_queen.cpp"

void printVec(std::vector<int> vec){
    for(auto v : vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main(){

    /*

    std::vector<int> arr = {5,2,4,7,1,3,2,6};

    std::vector<int> b;
    b.resize(arr.size());

    printVec(arr);

    selectionsort(arr);

    //mergesort(arr, b, 0, 7);

    printVec(arr);

    */

    return EXIT_SUCCESS;
}