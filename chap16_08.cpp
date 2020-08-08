#include "all.h"

// 自作find_if関数の実装
auto my_find_if(auto first, auto last, auto pred){

    for(auto iter = first; iter != last; iter++){
        if(pred(*iter)) return iter;
    }

    return last;
}

// find_ifによるfindの実装がしたいが・・・
int main(){

    std::vector<int> v = {1, 3, 5, 7, 9};
    int tgt = 3;

    auto my_find(auto first, auto last, auto num){

        auto temp_func = [&](auto tgt){if(tgt == num) return true; return false;};

        if(my_find_if(first, last, temp_func(tgt))) return iter;
    }
    
    auto pos = my_find(std::begin(v), std::end(v), tgt);
    if(*pos != std::end(v)) std::cout << "find" << std::endl;
    else std::cout << "nothing" << std::endl;

    return 0;
}