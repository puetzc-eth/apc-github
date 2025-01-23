#include <iostream>

struct rectangle{
    unsigned int width = 0;
    unsigned int height = 0;
};

struct circle{
    unsigned int radius = 0;
};

union shape{
    rectangle rect;
    circle circ;
};

int main(){
    rectangle myrect = {50, 20};
    circle mycirc = {10};
    shape myshape = {0,0};

    // shape is now a rectangle
    myshape.rect = myrect;
    std::cout << myshape.rect.width << " " << myshape.rect.height << std::endl;
    // output: 50 20

    // shape is now a circle (rect is overwritten)
    myshape.circ = mycirc;
    std::cout << myshape.circ.radius << std::endl;
    // output: 10

    //asking for the previous type (unions are not type safe)
    std::cout << myshape.rect.width << " " << myshape.rect.height << std::endl;
    // output: 10 20
    // 10 from the radius and 20 from the height that was not overwritten
}