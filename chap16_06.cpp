#include "all.h"

// pred関数の実装
bool pred1(int a){
    if(a == 5){
        std::cerr << "called" << std::endl;
        return true;
    }
}
bool pred2(int a){
    if(a == 100) return true;
}

// 自作find_if関数の実装
auto my_find_if(auto first, auto last, auto pred){

    int cnt = 0;
    for(auto iter = first; iter != last; iter++){
        cnt++;
        std::cout << "cnt = " << cnt << std::endl;
        if(pred(*iter)) return iter;
    }

    return last;
}

int main(){

    std::vector<int> v;
    for(int i = 0; i < 50; i++){
        v.push_back(i);
    }

    std::cout << *my_find_if(std::begin(v), std::end(v), pred1);

    return 0;
}