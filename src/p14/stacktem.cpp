#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;
int main(void){
    Stack<std::string> st;  //构造一个空的栈
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order," << endl
         << "P to process a PO, or Q to quit." << endl;
    while(cin >> ch && std::toupper(ch) != 'Q'){
        while(cin.get() != '\n'){   //消耗输入缓冲
            continue;
        }
        if(!std::isalpha(ch)){
            cout << '\a';   //警报音
            continue;
        }
        switch(std::toupper(ch)){
            case 'A':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isFull()){
                    cout << "stack already full" << endl;
                }else{
                    st.push(po);
                }
                break;
            case 'P':
                if(st.isEmpty()){
                    cout << "stack already empty" << endl;
                }else{
                    st.pop(po);
                    cout << "PO #" << po << " poped" << endl;
                }
                break;
        }
        cout << "Please enter A to add a purchase order," << endl
         << "P to process a PO, or Q to quit." << endl;
    }
    cout << "bye." << endl;
    cin.get();
    return 0;
}
