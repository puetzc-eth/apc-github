#include <iostream>
#include <vector>

const unsigned int QUEUE_SIZE = 100;

class queue
{
private:
    unsigned int head;
    unsigned int tail;
    unsigned int count;
    int data[QUEUE_SIZE];
public:
    queue() : head(0), tail(0), count(0){};
    ~queue() = default;

    void push(int item);
    int pop();
    int get_count();
};

void queue::push(const int item){
    if(count < STACK_SIZE - 1){
        data[count++] = item;
    } else {
        std::cerr << "Stack overflow" << std::endl;
    }
}

int queue::pop(){
    if(count > 0){
        return data[--count];
    } else {
        std::cerr << "Empty stack" << std::endl;
        return -1;
    }
}

int queue::get_count(){ //also get_count()
    return count;
}


int main(){

    std::cout << "hallo" << std::endl;

    return EXIT_SUCCESS;
}