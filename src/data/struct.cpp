struct rectangle{
    unsigned int width = 0;
    unsigned int height = 0;
};

// usage
struct rectangle myrect;
myrect.width = 10;
myrect.height = 20;

struct rectangle myrect2 = {50, 20};