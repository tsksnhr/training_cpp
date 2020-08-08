#include "all.h"

// 自作count関数の実装
auto my_count(auto first, auto last, auto value){

    int cnt = 0;
    for(auto iter = first; iter != last; iter++){
        if(*iter == value) cnt++;
    }

    return cnt;
}

int main(){

    std::vector<int> v = {1, 1, 2, 1, 2};

    std::cout << my_count(std::begin(v), std::end(v), 1) << std::endl;
    std::cout << my_count(std::begin(v), std::end(v), 2) << std::endl;
    std::cout << my_count(std::begin(v), std::end(v), 3) << std::endl;

    return 0;
}