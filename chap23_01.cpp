#include "all.h"

// テンプレート
template <typename T>

// templateを用いた関数定義
auto func1(T a){

    return a*5;
}

// test用main関数
int main(){

    std::cout << func1(10) << std::endl;
    std::cout << func1(10.3) << std::endl;

    // error
//    std::cout << func1("12.3"s) << std::endl;

    return 0;
}