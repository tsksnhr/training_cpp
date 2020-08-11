#include "all.h"

int main(){

    int a;

    // 後置演算子の評価
    a = 10;
    std::cout << a++ << std::endl;      // 10
    std::cout << a << std::endl;        // 11
    a = 10;
    std::cout << a-- << std::endl;      // 10
    std::cout << a << std::endl;        // 9

    // 前置演算子の評価
    a = 10;
    std::cout << ++a << std::endl;      // 11
    std::cout << a << std::endl;        // 11
    a = 10;
    std::cout << --a << std::endl;      // 9
    std::cout << a << std::endl;        // 9

    return 0;
}