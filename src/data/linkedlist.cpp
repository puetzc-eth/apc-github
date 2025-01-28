#include <iostream>

class linked_list
{
private:
    struct item{
        int value;
        item *ptr_next = nullptr;
    };
    item *ptr_first = nullptr;

public:
    //linked_list() = default;
    linked_list() : ptr_first(NULL) {};
    ~linked_list();
    // linked_list(const linked_list &) = delete;
    // linked_list &operator=(const linked_list &) = delete;
    void add_item(int v);
    bool has_item(int v);
    void add_item_in_order(int v);
};

void linked_list::add_item(int v){
    item *ptr_new = new item;        // pointer to the next item in the list
    (*ptr_new).value = v;            // set value
    (*ptr_new).ptr_next = ptr_first; // insert it at the front
    ptr_first = ptr_new;
}

bool linked_list::has_item(int v){
    // pointer to the current item
    item *ptr_current = ptr_first;
    while ((ptr_current != nullptr) && (ptr_current->value != v)){
        ptr_current = ptr_current->ptr_next;
    }
    // if ptr_current is nullptr (return false), we fell off the end of
    // the list and did not find the value
    return (ptr_current != nullptr);
}

void linked_list::add_item_in_order(int v){
    // first element or insertion at the beginning
    if ((ptr_first == nullptr) || (v < ptr_first->value)){
        add_item(v);
    } else {
        // locate the insertion point
        item *ptr_before;            // insert after this element
        item *ptr_after = ptr_first; // insert before this element
        while (true){
            ptr_before = ptr_after;
            ptr_after = ptr_after->ptr_next;
            if (ptr_after == nullptr) // check for end of list
                break;
            // insertion point located?
            if (v >= ptr_before->value && v < ptr_after->value)
                break;
        }
        // insert element
        item *ptr_new = new item;
        ptr_new->value = v;
        ptr_before->ptr_next = ptr_new;
        ptr_new->ptr_next = ptr_after;
    }
}

int main(){

    linked_list mylist;

    //mylist.add_item(10);

    std::cout << "end" << std::endl;

    return EXIT_SUCCESS;
}