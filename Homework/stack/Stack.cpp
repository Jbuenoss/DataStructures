#include <iostream>
#include "Stack.h"

Stack::Stack(){
    array = new data[maxSize];
    size = 0;
}

Stack::~Stack(){
    delete [] array;
}

bool Stack::isFull(){
    return size == maxSize;
}

bool Stack::empty(){
    return size == 0;
}

void Stack::push(data elem){
    if(isFull())        std::cout << "It's not possible to push, the stack is full!\n";
    else{
        array[size] = elem;
        size++;
    }
}

void Stack::pop(){
    if(empty())         std::cout << "It's not possible to pop, the stack is empty\n";
    else                size--;
}

void Stack::back(){
    if(empty())         std::cout << "the stack has no elements\n";
    else{
        std::cout << "Back: " << array[size-1] << '\n';
    }
}