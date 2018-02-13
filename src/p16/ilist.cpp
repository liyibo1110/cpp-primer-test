#include <iostream>
#include <initializer_list>

using namespace std;

double sum(initializer_list<double>);
double average(const initializer_list<double> &);

int main(){
    cout << "List 1: sum = " << sum({2,3,4}) 
         << ", avg = " << average({2,3,4}) << endl;

    initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "List 2: sum = " << sum(dl) 
         << ", avg = " << average(dl) << endl;

    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "List 3: sum = " << sum(dl) 
         << ", avg = " << average(dl) << endl;

    cin.get();
    cin.get();
    return 0;
}

double sum(initializer_list<double> il){
    double total = 0;
    for (auto p = il.begin(); p != il.end(); p++){
        total += *p;
    }
    return total;
}

double average(const initializer_list<double> & ril){
    double total = 0;
    double avg = 0.0;
    if(ril.size() > 0){
        for (auto p = ril.begin(); p != ril.end(); p++){
            total += *p;
        }
        avg = total / ril.size();
    }
    return avg;
}