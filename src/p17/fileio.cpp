#include <fstream>
#include <iostream>
#include <string>

int main(){
    using namespace std;

    string filename;
    cout << "Enter name for new file: ";
    cin >> filename;

    ofstream fout(filename.c_str());
    fout << "For your eyes only!" << endl;
    cout << "Enter your secret number: ";
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close();

    //开始读取文件
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":" << endl;
    char ch;
    while(fin.get(ch)){
        cout << ch;
    }
    cout << "Done" << endl;
    fin.close();
    cin.get();
    cin.get();
    return 0;
}