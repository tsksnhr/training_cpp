#include "all.h"

// 自作transform関数の実装
auto my_transform(auto first, auto last, auto result, auto op){

    for(auto iter = first; iter != last; iter++, result++){
        *result = op(*iter);
    }

    return result;
}

// test用main関数
int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> u(5);

    auto op = [](int a){return a*a;};
    auto iter = my_transform(std::begin(v), std::end(v), std::begin(u), op);

    for(auto x: u) std::cout << x << std::endl;

    std::cout << std::boolalpha;
    std::cout << (iter == std::begin(u) + (std::end(v) - std::begin(v)));     // true

    return 0;
}