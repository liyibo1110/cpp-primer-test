#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>
class BadHmean{
    private:
        double v1;
        double v2;
    public:
        BadHmean(double a = 0, double b = 0) : v1(a), v2(b){}
        void mesg();
};

inline void BadHmean::mesg(){
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b" << std::endl;
}

class BadGmean{
    public:
        double v1;
        double v2;
        BadGmean(double a = 0, double b = 0) : v1(a), v2(b){}
        const char * mesg();
};

inline const char * BadGmean::mesg(){
    return "gmean() arguments should be >= 0\n";
}
#endif