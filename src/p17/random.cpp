#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline(){
    while(std::cin.get() != '\n'){
        continue;
    }
}

const int LIMIT = 20;

struct planet{
    char name[LIMIT];
    double population;
    double g;
};

const char *file = "planets.dat";

int main(){
    using namespace std;
    planet pl;
    cout << fixed << right;

    fstream finout; //同时读写
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    int count = 0;
    if(finout.is_open()){
        finout.seekg(0);    //不一定需要
        cout << "Here are the current contents of the " << file << " file:" << endl;
        //读取旧数据
        while(finout.read((char *)&pl, sizeof(pl))){
            cout << ++count << ": " << setw(LIMIT) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        if(finout.eof()){
            finout.clear();
        }else{
            cerr << "Error in reading " << file << "." << endl;
        }


    }else{
        cerr << file << " could not be opened -- bye." << endl;
        exit(EXIT_FAILURE);
    }
    
    //修改数据
    cout << "Enter the record number you wish to change: ";
    long record;
    cin >> record;
    eatline();
    if(record < 1 || record > count){
        cerr << "Invalid record number -- bye" << endl;
        exit(EXIT_FAILURE);
    }
    streampos place = (record - 1) * sizeof(pl);
    finout.seekg(place);
    if(finout.fail()){
        cerr << "Error on attempted seek" << endl;
        exit(EXIT_FAILURE);
    }
    finout.read((char *)&pl, sizeof(pl));
    cout << "Your selection:" << endl;
    cout << record << ": " << setw(LIMIT) << pl.name << ": "
         << setprecision(0) << setw(12) << pl.population
         << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof()){
        finout.clear();
    }

    //开始修改
    cout << "Enter planet name: ";
    cin.get(pl.name, LIMIT);
    eatline();
    cout << "Enter planetary popualtion: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekg(place);    //回到本条记录起始位置
    finout.write((char *)&pl, sizeof(pl)) << flush;
    if(finout.fail()){
        cerr << "Error on attempted write" << endl;
        exit(EXIT_FAILURE);
    }

    //展示修改后的记录
    count = 0;
    finout.clear();
    cout << "Here are the new contents of the " << file << " file:" << endl;
    while(finout.read((char *)&pl, sizeof(pl))){
        cout << ++count << ": " << setw(LIMIT) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close();
    cout << "Done." << endl;
    return 0;
}