#include <iostream>
#include "tv.h"

int main(void){
    using std::cout;
    using std::endl;
    Tv s42;
    cout << "Initial setting for 42 TV: " << endl;
    s42.setting();
    s42.onoff();
    s42.chanup();
    cout << "Adjusted setting for 42 TV: " << endl;
    s42.chanup();
    cout << "Adjusted setting for 42 TV: " << endl;
    s42.setting();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "42 settings after using remote:" << endl;
    s42.setting();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "58 settings:" << endl;
    s58.setting();

    std::cin.get();

    return 0;
}