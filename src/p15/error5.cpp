#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"

class Demo{
    private:
      std::string word;
    public:
      Demo(const std::string & str){
          word = str;
          std::cout << "demo " << word << " created" << std::endl;
      }
      ~Demo(){
          std::cout << "demo " << word << " destroyed" << std::endl;
      }
      void show()const{
          std::cout << "demo " << word << " lives!" << std::endl;
      }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    double x, y, z;
    {
        Demo d1("found in block in main()");
        cout << "Enter two numbers: ";
        while(cin >> x >> y){
            try{
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
                cout << "Enter next pair: ";
            }catch(BadHmean & bg){
                bg.mesg();
                cout << "Try again." << endl;
                continue;
            }catch(BadGmean & hg){
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
                break;
            }
        }
        d1.show();
    }
    cout << "Bye!" << endl;
    cin.get();
    cin.get();
    return 0;
}

double hmean(double a, double b){
    if(a == -b){
        throw BadHmean(a, b);
    }
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b){
    if(a < 0 || b < 0){
        throw BadGmean(a, b);
    }
    return std::sqrt(a * b);
}
double means(double a, double b){
    double am, hm, gm;
    Demo d2("found in means()");
    am = (a + b) / 2.0;
    try{
        hm = hmean(a, b);
        gm = gmean(a, b);
    }catch(BadHmean & bg){
        bg.mesg();
        std::cout << "Caught in means()" << std::endl;
        throw;
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}