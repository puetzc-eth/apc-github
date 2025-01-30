#include <iostream>

int main(){

    int thing = 4;
    int *ptr_thing = &thing;
    *ptr_thing = 5;

    std::cout << thing << " " << *ptr_thing << std::endl;

    return EXIT_SUCCESS;
}