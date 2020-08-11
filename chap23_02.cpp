#include "all.h"

// 関数template
template <typename vec>

// templateを用いた関数宣言
void add_zero(vec &v){

    // 引数にとったvectorに0を追加する関数
    v.push_back(0);
}

// test用main関数
int main(){

    std::vector<int> a;
    add_zero(a);

    std::vector<int> b;
    add_zero(b);

    std::vector<int> c;

    std::cout << "a = ";
    for(auto x: a) std::cout << x << std::endl;

    std::cout << "b = ";
    for(auto x: b) std::cout << x << std::endl;
    
    std::cout << "c = ";
    for(auto x: c) std::cout << x << std::endl;

    return 0;
}