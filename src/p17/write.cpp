#include <iostream>
#include <cstring>

int main(){
    using namespace std;
    const char *state1 = "Florida";
    const char *state2 = "Kansas";
    const char *state3 = "Euphoria";
    int len = strlen(state2);
    cout << "Increasing loop index:" << endl;
    for (int i = 0; i <= len; i++){
        cout.write(state2, i) << endl;
    }

    cout << "Decreasing loop index:" << endl;
    for (int i = len; i > 0; i--){
        cout.write(state2, i) << endl;
    }

    cout << "Exceeding string length:" << endl;
    cout.write(state2, len + 5) << endl;

    cin.get();
    cin.get();
    return 0;
}