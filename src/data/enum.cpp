#include <iostream>

enum workday{
    Monday,     // 0
    Tuesday,    // 1
    Wednesday,  // 2
    Thursday,   // 3
    Friday      // 4
};

int main(){
    workday today = Wednesday;
    workday tomorrow = Thursday;   
    auto yesterday = workday::Tuesday; // alternative syntax

    std::cout << today << " " << tomorrow << " " << yesterday << std::endl;
    // output: 2 3 1

    std::cout << today + tomorrow <<std::endl;
    // output: 5
    // automatic conversion to int

    return 0;
}