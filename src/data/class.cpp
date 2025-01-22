class rectangle
{
private:
    unsigned int width = 0;
    unsigned int height = 0;

public:
    rectangle() = default;                           // use default constructor
    rectangle(unsigned int w, unsigned int h);       // constructor
    rectangle(const rectangle &old_rect);            // copy constructor
    rectangle &operator=(const rectangle &old_rect); // assignment operator
    ~rectangle() = default;                          // use default destructor
    void set_width(unsigned int w);
    unsigned int get_width() const;
    void set_height(unsigned int h);
    unsigned int get_height() const;
};

rectangle::rectangle(unsigned int w, unsigned int h){
    width = w;
    height = h;
}

rectangle::rectangle(const rectangle &old_rect){
    width = old_rect.width;
    height = old_rect.height;
}
rectangle &rectangle::operator=(const rectangle &old_rect){
    if (this == &old_rect){
        return *this;
    }
    width = old_rect.width;
    height = old_rect.height;
    return *this;
}

void rectangle::set_width(unsigned int w){
    width = w;
}

unsigned int rectangle::get_width() const{
    return width;
}

void rectangle::set_height(unsigned int h){
    height = h;
}

unsigned int rectangle::get_height() const{
    return height;
}