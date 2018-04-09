#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;


class List {
private:
    int data;
    List * next;
public:
    List();
    ~List();
    bool empty();
    void clear();
    List operator [] (int);
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    void insert();
    void eraser();
    List * front();
    List * end();
};

List::List() {
    data = -1;
    next = NULL;
}

List::~List() {
    clear();
}

bool List::empty() {
    if (this -> next == NULL)
        return true;
    return false;
}

void List::clear() {
    if (this -> next -> next != NULL) {
        (*(this -> next)).clear();
    }
    delete this -> next;
    this -> next = NULL;
}

List * List::front() {
    return this;
}

List * List::end() {
    if (this -> next == NULL) {
        return this;
    }

    List * __find = this;
    do {
        __find = __find -> next;
    } while (__find -> next != NULL);
    return __find;
}


void List::push_back(int __dat) {
    List * __end = end();
    __end -> next = new List;
    __end -> next -> next = NULL;
    __end -> data = __dat;
}

void List::push_front(int __dat) {
    List * __front = front();
    List * __new = new List;
    __new -> data = __dat;
    __new -> next = __front -> next;
    __front -> next = __new;
}
