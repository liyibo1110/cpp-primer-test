#include <iostream>

int main(){
    using namespace std;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0; 

    cout << "\"Furry Friends\" is $" << price1 << "!" << endl;
    cout << "\"Fiery Fiends\" is $" << price2 << "!" << endl;

    cout.precision(2);

    cout << "\"Furry Friends\" is $" << price1 << "!" << endl;
    cout << "\"Fiery Fiends\" is $" << price2 << "!" << endl;
    cin.get();
    cin.get();
    return 0;
}