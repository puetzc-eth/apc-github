#include <iostream>
#include <vector>

#include "class.cpp"

int main(){

    rectangle rect1;      // use first constructor
    rect1.set_width(10);  // set the width to 10
    rect1.set_height(20); // set the height to 20
    std::cout << rect1.get_width() << std::endl;
    
    rectangle rect2(30, 20); // use second constructor
    std::cout << rect2.get_height() << std::endl;
    
    rectangle rect3(rect1); // use copy constructor
    std::cout << rect3.get_width() << std::endl;
    
    rectangle rect4 = rect2; // use assignment operator
    std::cout << rect4.get_width() << std::endl;
    
    return EXIT_SUCCESS;
}