#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long SIZE = 390000L;

int main(){
    using namespace std;

    vector<int> numbers(SIZE);
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample size = " << SIZE << endl;

    //使用lambda
    int count3 = count_if(numbers.begin(), numbers.end(),
                          [](int x) {
                              return x % 3 == 0;
                          });
    cout << "Count of numbers divisible by 3: " << count3 << endl;
    int count13 = 0;
    for_each(numbers.begin(), numbers.end(),
             [&count13](int x) {
                 count13 += x % 13 == 0;
             });
    cout << "Count of numbers divisible by 13: " << count13 << endl;
    

    //使用混合lambda
    count3 = 0;
    count13 = 0;
    for_each(numbers.begin(), numbers.end(),
             [&](int x) {
                 count3 += x % 3 == 0;
                 count13 += x % 13 == 0;
             });

    cout << "Count of numbers divisible by 3: " << count3 << endl;
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    cin.get();
    cin.get();
    return 0;

}