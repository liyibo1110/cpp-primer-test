#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main(){

    using namespace std;
    multimap<int, string> codes;
    codes.insert(pair<const int, string>(415, "San Francisco"));
    codes.insert(pair<const int, string>(510, "Oakland"));
    codes.insert(pair<const int, string>(718, "Brooklyn"));
    codes.insert(pair<const int, string>(718, "Staten Island"));
    codes.insert(pair<const int, string>(415, "San Rafael"));
    codes.insert(pair<const int, string>(510, "Berkeley"));

    cout << "Number of cities with area code 415: " 
         << codes.count(415) << endl;
    cout << "Number of cities with area code 718: " 
         << codes.count(718) << endl;
    cout << "Number of cities with area code 510: " 
         << codes.count(510) << endl;
    cout << "Area Code  City" << endl;
    
    multimap<const int, string>::iterator it;

    //要如此迭代使用
    for (it = codes.begin(); it != codes.end(); ++it){
        cout << "   " << (*it).first << "   " << (*it).second << endl;
    }

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range 
            = codes.equal_range(718);
    cout << "Cities with area code 718:" << endl;
    for (it = range.first; it != range.second; ++it){
        cout << "   " << (*it).second << endl;
    }
    return 0;
}