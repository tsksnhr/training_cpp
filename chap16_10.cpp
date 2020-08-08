#include "all.h"

// 自作count_ifの実装
auto my_count_if(auto first, auto last, auto func){

    int cnt = 0;
    for(auto iter = first; iter != last; iter++){
        if(func(*iter) != false) cnt++;
    }
    return cnt;
}

// 判定用関数
bool func1(int a){
    if(a%2 == 0) return true;
    else return false;
}
bool func2(int a){
    if(a%7 == 0) return true;
    else return false;
}

// test用main関数
int main(){

    std::vector<int> v;
    for(int i = 0; i < 100; i++){
        v.push_back(i);
    }

    auto first = std::begin(v);
    auto last = std::end(v);
    std::cout << "test1 = " << my_count_if(first, last, func1) << std::endl;
    std::cout << "test2 = " << my_count_if(first, last, func2) << std::endl;

    return 0;
}