#include <iostream>
#include <vector>

int main () {

    std::vector<int> vec = {0,1,2,3,4,5};

    vec.push_back(6);

    for (auto v : vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;

    //std::cout << var[0] << std::endl;

    return EXIT_SUCCESS;
}