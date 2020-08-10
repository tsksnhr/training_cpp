#include "all.h"

// 自作copy関数の実装
auto my_copy(auto first, auto last, auto result){

    for(auto iter1 = first; iter1 != last; iter1++, result++){
        *result = *iter1;
    }

    return result;
}

// test用main関数
int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> u(5);

    auto iter = my_copy(std::begin(v), std::end(v), std::begin(u));

    for(auto x: u){
        std::cout << x << std::endl;
    }

    std::cout << std::boolalpha;
    std::cout << (iter == std::begin(u) + (std::end(v) - std::begin(v)));   // true

    return 0;
}