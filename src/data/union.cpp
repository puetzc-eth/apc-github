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
    std::cout << myshape.circ.radius << " " << myshape.rect.width << std::endl;
    // output: 10 10
}