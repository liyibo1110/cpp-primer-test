#include "somedefs.h"
#include <iostream>

double dub(double x){
    return 2.0 * x;
}
double square(double x){
    return x * x;
}

int main(){
    using namespace std;

    double y = 1.21;
    cout << "Function pointer dub:" << endl;
    cout << "   " << use_f(y, dub) << endl;

    cout << "Function pointer square:" << endl;
    cout << "   " << use_f(y, square) << endl;

    cout << "Function object Fp:" << endl;
    cout << "   " << use_f(y, Fp(5.0)) << endl;

    cout << "Function object Fq:" << endl;
    cout << "   " << use_f(y, Fq(5.0)) << endl;

    cout << "Lambda expression 1:" << endl;
    cout << "   " << use_f(y, [](double u) { return u * u; }) << endl;

    cout << "Lambda expression 2:" << endl;
    cout << "   " << use_f(y, [](double u) { return u + u/2.0; }) << endl;

    cin.get();
    cin.get();
    return 0;
}