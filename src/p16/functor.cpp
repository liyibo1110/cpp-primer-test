#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

template<typename T>
class TooBig{
    private:
        T cutoff;
    public:
        TooBig(const T & t) : cutoff(t) {}
        bool operator()(const T & v){
            return v > cutoff;
        };
        
};

void outint(int n){
    std::cout << n << " ";
}

int main(){

    using namespace std;
    TooBig<int> f100(100);  //限定值为100
    int vals[10] = {50, 100, 90, 180, 60,
                    210, 415, 88, 188, 201};

    list<int> list1(vals, vals + 10);
    list<int> list2(vals, vals + 10);

    cout << "Original lists:" << endl;
    for_each(list1.begin(), list1.end(), outint);
    cout << endl;
    for_each(list2.begin(), list2.end(), outint);
    cout << endl;

    //使用显式实名的函数算子对象
    list1.remove_if(f100);
    cout << endl;
    //改成直接构造函数算子对象的方式也可以
    list2.remove_if(TooBig<int>(200));

    cout << "Trimmed lists:" << endl;
    for_each(list1.begin(), list1.end(), outint);
    cout << endl;
    for_each(list2.begin(), list2.end(), outint);
    cout << endl;
    return 0;
}