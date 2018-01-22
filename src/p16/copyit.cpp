#include <iostream>
#include <iterator>
#include <vector>

int main(){
    using namespace std;
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dict(10);
    //从数组copy到vector
    copy(casts, casts + 10, dict.begin());
    cout << "Let the dice be cast!" << endl;

    //创建一个os的迭代器
    ostream_iterator<int, char> out_iter(cout, " ");
    //从vector复制到os
    copy(dict.begin(), dict.end(), out_iter);
    cout << endl;

    cout << "Implicit use of reverse iterator." << endl;
    //隐式反向输出
    copy(dict.rbegin(), dict.rend(), out_iter);
    cout << endl;

    //显式反向输出
    cout << "Explicit use of reverse iterator." << endl;
    vector<int>::reverse_iterator ri;
    for (ri = dict.rbegin(); ri != dict.rend(); ++ri){
        cout << *ri << " ";
    }
    cout << endl;
    return 0;
}