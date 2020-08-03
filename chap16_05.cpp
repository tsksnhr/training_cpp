#include "all.h"

// 自作find関数の実装
auto my_find(auto first, auto last, auto const &value){

    for(auto iter = first; iter != last; iter++){
        if(*iter == value) return iter;
    }

    return last;
}

int main(){

    std::vector<int> v = {1, 3, 5, 7, 9};
    int v1 = 5, v2 = 12;
//    int &rv1 = v1, &rv2 = v2;

    // find
    auto pos = my_find(std::begin(v), std::end(v), v1);
    if(*pos == v1) std::cout << "find." << std::endl;
    else std::cout << "Nothing." << std::endl;

    // nothing
    pos = my_find(std::begin(v), std::end(v), v2);
    if(*pos == v2) std::cout << "find." << std::endl;
    else std::cout << "nothing." << std::endl;

    return 0;
}