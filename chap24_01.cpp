#include "all.h"

// template
template<typename T, std::size_t size_num>

// class定義
struct my_array{

    // エイリアス
    using value_type = T;
    using reference = T &;

    value_type data[size_num];

    reference operator [](std::size_t snum){
        return data[snum];
    }

};

// test用main関数
int main(){

    my_array<int, 5> ma1;
    ma1 = {0,1,2,3,4};

    // エイリアス
    using value_array = my_array<int, 5>;

    // my_array<int, 5>のvalue_typeはintなので、value_array::value_typeはint型になる
    value_array::value_type ma2 = 0;
    // value_typeへの参照がreferenceなので、intへの参照になる
    value_array::reference ref = ma1[2];
    ref = 10;

    std::cout << "ma1 = "s;
    for(int i = 0; i < 5; i++) std::cout << ma1[i] << " ";
    std::cout << std::endl;

    std::cout << "ma2 = ";
    std::cout << ma2 << " ";
    std::cout << std::endl;

    return 0;
}