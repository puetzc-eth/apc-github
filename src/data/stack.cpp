#include <iostream>

const unsigned int STACK_SIZE = 100;

class stack
{
private:
    unsigned int count;
    int data[STACK_SIZE];
public:
    stack() : count(0){};
    ~stack() = default;

    void push(int item);
    int pop();
    bool stack_empty();
    int stack_size();
};

void stack::push(const int item){
    if(count < STACK_SIZE - 1){
        data[count++] = item;
    } else {
        std::cerr << "Stack overflow" << std::endl;
    }
}

int stack::pop(){
    if(count > 0){
        return data[--count];
    } else {
        std::cerr << "Empty stack" << std::endl;
        return -1;
    }
}

bool stack::stack_empty(){
    return (count == 0);
}

int stack::stack_size(){ //also get_count()
    return count;
}


int main(){

    //std::cout << "hallo" << std::endl;

    stack mystack;

    mystack.push(1);
    mystack.push(2);

    std::cout << mystack.pop() << " " << mystack.pop() << std::endl;

    return EXIT_SUCCESS;
}