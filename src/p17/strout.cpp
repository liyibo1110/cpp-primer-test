#include <iostream>
#include <sstream>
#include <string>

int main(){
    using namespace std;
    ostringstream outstr;
    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    cout << "What's its capacity in GB? ";
    int cap;
    cin >> cap;

    outstr << "The hard disk " << hdisk << " has a capacity of "
           << cap << " gigabyte ." << endl;
    string result = outstr.str();
    cout << result;
    cin.get();
    cin.get();
    return 0;
}