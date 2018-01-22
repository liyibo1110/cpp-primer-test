#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <typename T, int n>
class ArrayTP{
    private:
      T ar[n];
    public:
      ArrayTP(){};
      explicit ArrayTP(const T &v);
      virtual T &operator[](int i);
      virtual T operator[](int i)const;
};

//实现
template <typename T, int n>
ArrayTP<T, n>::ArrayTP(const T &v){
    for (int i = 0; i < n; i++){
        
    }
}
#endif;