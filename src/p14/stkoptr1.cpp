#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stcktp1.h"
const int NUM = 10;

int main(void){
    std::srand(std::time(0));   //设定随机种子
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    
    //创建模版类
    Stack<const char *> st(stacksize);
    //构建模拟数据
    const char *in[NUM] = {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", " 10: Misha Mache"};
    const char *out[NUM];

    int processed = 0;
    int nextin = 0;

    while(processed < NUM){
        if(st.isEmpty()){    //栈是空，直接丢一个新的
            st.push(in[nextin]);
            nextin++;
        }else if(st.isFull()){  //栈满了，直接出来一个存到out里
            st.pop(out[processed]);
            processed++;
        }else if(std::rand() % 2 && nextin < NUM){  //50%几率进入
            st.push(in[nextin]);
            nextin++;
        }else{
            st.pop(out[processed]);
            processed++;
        }
    }

    for (int i = 0; i < NUM;i++){
        std::cout << out[i] << std::endl;
    }

    std::cout << "bye." << std::endl;
    std::cin.get();
    return 0;
}