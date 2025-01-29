#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

const int MAX_LENGTH = 100;

class rectangle
{
    friend class canvas;

private:
    unsigned int width = 0;
    unsigned int height = 0;
    static unsigned int rect_count;  // number of rectangles created (static member) in every constructor

public:
    const int MAX_LENGTH = 100;
    static unsigned int get_count();

    rectangle() = default;                           // use default constructor
    rectangle(unsigned int w, unsigned int h);       // constructor
    rectangle(int w, int h);                         // constructor in modern C++
    rectangle(const rectangle &old_rect);            // copy constructor
    ~rectangle() = default;                          // use default destructor

    rectangle &operator=(const rectangle &old_rect); // assignment operator

    void set_width(unsigned int w);
    unsigned int get_width() const;
    void set_height(unsigned int h);
    unsigned int get_height() const;
    
    friend bool equal(const rectangle &r1, const rectangle &r2); //friend function

    virtual void print_properties(); //virtual functions for child classes
};

unsigned int rectangle::rect_count = 0; // muss man ausserhalb initialisieren aber in der Klasse deklarieren

unsigned int rectangle::get_count(){
    return rect_count;
}

// constructor
rectangle::rectangle(unsigned int w, unsigned int h){
    width = w;
    height = h;
    ++rect_count;
}

// constructor in modern C++
rectangle::rectangle(int w, int h){
    width = std::min(w, MAX_LENGTH);
    height = std::min(h, MAX_LENGTH); 
    ++rect_count;
}

// copy constructor
rectangle::rectangle(const rectangle &old_rect){
    width = old_rect.width;
    height = old_rect.height;
    ++rect_count;
}

// assignement operator
rectangle &rectangle::operator=(const rectangle &old_rect){
    if (this == &old_rect){
        return *this;
    }
    width = old_rect.width;
    height = old_rect.height;
    return *this;
}

// setter
void rectangle::set_width(unsigned int w){
    width = w;
}

//getter
unsigned int rectangle::get_width() const{
    return width;
}

void rectangle::set_height(unsigned int h){
    height = h;
}

unsigned int rectangle::get_height() const{
    return height;
}

bool equal(const rectangle &r1, const rectangle &r2){
    return r1.width == r2.width && r1.height == r2.height;
}

// virtual function for print properties
void rectangle::print_properties(){
    std::cout << "Width = " << width << std::endl;
    std::cout << "Height = " << height << std::endl;
}

// friend class of class rectangle
class canvas
{
private:
    std::vector<rectangle> members;
public:
    canvas() = default;
    ~canvas() = default;
    int coveredArea();
};

int canvas::coveredArea(){
    unsigned int sum = 0;
    for(const auto &member : members){
        sum += member.width * member.height;
    }
    return sum;
}

// inheritance with private

class square : private rectangle //public members of rectangle become private in square
{
public:
    square() = default;
    square(unsigned int l) : rectangle(1, 1) {}; // constructor with rectangle constructor
    ~square() = default;

    void set_length(unsigned int l);
    unsigned int get_length() const;
};

void square::set_length(unsigned int l){ 
    set_width(l); 
    set_height(l);
    //wenn width und heigth in der parent class protected und nicht private sind geht auch:
    //width = l;
    //heigth = l;
}

unsigned int square::get_length() const{
    return get_width();
    //wenn width und heigth in der parent class protected und nicht private sind geht auch:
    //return width;
}

// inheritance with public

class colRectangle : public rectangle
{
private:
    std::string color = "black";
public:
    colRectangle() : rectangle() {};
    colRectangle(unsigned int w, unsigned int h, const std::string &c);
    ~colRectangle() = default;

    void set_color(const std::string &c);
    std::string get_color();

    void print_properties();
};

colRectangle::colRectangle(unsigned int w, unsigned int h, const std::string &c) : rectangle(w, h){
    color = c;
}

void colRectangle::set_color(const std::string &c){
    color = c;
}

std::string colRectangle::get_color(){
    return color;
}

void colRectangle::print_properties(){
    rectangle::print_properties();
    std::cout << "Color = " << color << std::endl;
}

int main(){

    std::cout << "hallo" << std::endl;

    rectangle myrect = {10, 20};
    rectangle myrect2 = {20, 30};

    int count1 = myrect.get_count();

    int count3 = rectangle::get_count(); //static function kann auch ohne oblekt aufgerufen werden

    std::cout << count1 << " " << count3 << std::endl; //sind gleich
    
    //consts ausprobieren

    //chield class

    colRectangle c(10, 20, "blue");

    std::cout << c.get_width() << " " << c.get_height() << " " << c.get_color() << std::endl;

    // virtual function

    myrect.print_properties();
    c.print_properties();

    return EXIT_SUCCESS;
}