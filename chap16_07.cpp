#include "all.h"

int main(){

    int value;
    std::cout << "type num: ";
    std::cin >> value;

    // ラムダ式による外部変数の利用
    auto func1 = [=]{return value;};
    auto func2 = [&]{return value + 1;};

    std::cout << "value = " << func1() << std::endl;
    std::cout << "value + 1 = " << func2() << std::endl;

    return 0;
}