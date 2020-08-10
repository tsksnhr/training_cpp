#include "all.h"

// 自作replace関数の実装
auto my_replace(auto first, auto last, auto old_value, auto new_value){

    for(auto iter = first; iter != last; iter++){
        if(*iter == old_value) *iter = new_value;
    }

}

// test用main関数
int main(){

    std::vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    for(auto x: v) std::cout << x << " ";
    std::cout << std::endl;

    int old_v = 5, new_v = 10;
    my_replace(std::begin(v), std::end(v), old_v, new_v);

    for(auto x: v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}