#include "all.h"

// pred定義
bool pred1(int a){
    if(a%2==0) return true;
    else return false;
}
bool pred2(int a){
    if(a*2>10) return true;
    else return false;
}

// 自作all_ofの実装
auto my_all_of(auto first, auto last, auto pred){

    for(auto iter = first; iter != last; iter++){
        
        // 一つでもpredを満たさない*iterがあればfalseを返す
        if(pred(*iter) == false) return false;
    }

    return true;
}

int main(){

    std::vector<int> v = {10, 11, 12, 13, 14, 15};

    std::cout << std::boolalpha;
    std::cout << my_all_of(std::begin(v), std::end(v), pred1) << std::endl; // false
    std::cout << my_all_of(std::begin(v), std::end(v), pred2) << std::endl; // true

    return 0;
}