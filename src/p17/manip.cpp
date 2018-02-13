#include <iostream>

int main(){
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "n  n*n" << endl;
    cout << n << "   " << n * n << " (decimal)" << endl;
    //设为16进制
    cout << hex;
    cout << n << "   ";
    cout << n * n << " (hexdecimal)" << endl;
    //设为8进制
    cout << oct << n << "   " << n * n << "(octal)" << endl;

    dec(cout);
    cout << n << "   " << n * n << " (decimal)" << endl;

    cin.get();
    cin.get();
    return 0;
}