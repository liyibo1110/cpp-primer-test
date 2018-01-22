#ifndef STACKTP_H_
#define STACKTP_H_
#include<iostream>
template <typename T>
class Stack{
    private:
        enum{MAX = 10};
        T items[MAX];
        int top;
    public:
      Stack();
      bool isEmpty();
      bool isFull();
      bool push(const T &item);
      bool pop(T &item);
};

//直接实现
template <typename T>
Stack<T>::Stack(){
    top = 0;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return top == 0;
}

template <typename T>
bool Stack<T>::isFull(){
    return top == MAX;
}

template <typename T>
bool Stack<T>::push(const T &item){
    if(isFull()){
        return false;
    }else{
        //std::cout << "item: " << item << " add" << std::endl;
        items[top] = item;
        top++;
        return true;
    }
}

template <typename T>    
bool Stack<T>::pop(T &item){
    if(isEmpty()){
        return false;
    }else{
        top--;
        item = items[top];
        //std::cout << "item: " << item << " poped" << std::endl;
        return true;
    }
    
}

#endif