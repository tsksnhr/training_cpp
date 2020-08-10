#include "all.h"

// 自作fill関数の実装
auto my_fill(auto first, auto last, auto value){

    for(auto iter = first; iter != last; iter++) *iter = value;
}

// test用main関数
int main(){

    std::vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(i);

    for(auto x: v) std::cout << x << " ";
    std::cout << std::endl;

    int value = 7;
    my_fill(std::begin(v), std::end(v), value);

    for(auto x: v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}