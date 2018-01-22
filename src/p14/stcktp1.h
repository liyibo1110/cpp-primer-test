#ifndef STCKTP_H_
#define STCKTP_H_
template <typename T>
class Stack{
    private:
        enum{SIZE = 10};    //默认大小
        int stacksize;
        T *items;
        int top;
    public:
      explicit Stack(int ss = SIZE);
      Stack(const Stack &st);
      Stack &operator=(const Stack &st);
      ~Stack() { delete[] items; }
      bool isEmpty() { return top == 0;}
      bool isFull() { return top == stacksize; }
      bool push(const T &item);
      bool pop(T &item);
};

//直接实现
template <typename T>
Stack<T>::Stack(int ss) : stacksize(ss), top(0){
    items = new T[stacksize];
}

template <typename T>
Stack<T>::Stack(const Stack &st) {
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];
    for (int i = 0; i < stacksize;i++){
        items[i] = st.items[i];
    }
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &st){
    //例行2步，判断是否为自己，清理左值的动态内容
    if(this == &st){
        return *this;
    }
    delete[] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];
    for (int i = 0; i < stacksize;i++){
        items[i] = st.items[i];
    }
}

template <typename T>
bool Stack<T>::push(const T &item){
    if(isFull()){
        return false;
    }else{
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