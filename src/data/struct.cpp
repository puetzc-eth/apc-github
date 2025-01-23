struct rectangle{
    unsigned int width = 0;
    unsigned int height = 0;
};

int main(){
    rectangle myrect;
    myrect.width = 10;
    myrect.height = 20;

    rectangle myrect2 = {50, 20};

    return 0;
}