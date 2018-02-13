#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <cctype>
#include <algorithm>

using namespace std;

char toLower(char ch){
    return tolower(ch);
}   
string & ToLower(string & st){
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}
void display(const string &s){
    cout << s << " ";
}

int main(){
    vector<string> words;
    cout << "Enter words (enter quit to quit):" << endl;
    string input;
    while(cin >> input && input != "quit"){
        words.push_back(input);
    }

    cout << "You entered the following words:" << endl;
    for_each(words.begin(), words.end(), display);
    cout << endl;

    //全部小写，并转移到set里
    set<string> wordset;
    transform(words.begin(), words.end(),
            insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
    cout << endl;
    cout << "Alphabetic list of words:" << endl;
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    //将统计字母数字存到map里
    map<string, int> wordmap;
    set<string>::iterator si;
    for (si = wordset.begin(); si != wordset.end(); si++){
        wordmap[*si] = count(words.begin(), words.end(), *si);
    }

    //输出map
    cout << endl;
    cout << "Word frequency:" << endl;  
    for (si = wordset.begin(); si != wordset.end(); si++){
        cout << *si << ": " << wordmap[*si] << endl;
    }
    cin.get();  //会读取cin>>遗留的换行符，所以不会暂停
    cin.get();
    return 0;
}