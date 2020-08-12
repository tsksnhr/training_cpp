#include "all.h"

// class template
template <typename T, std::size_t size_num>

// class定義
struct my_array{

    // エイリアス(ネストされた型名)
    using data_type = T;
    using reference = T &;
    using const_reference = T const &;

    // 関数の宣言
    data_type data[size_num];

    // []演算子のオーバーロード
    data_type & operator [](std::size_t snum){
        return data[snum];
    }

    // my_arrayのサイズを返すmy_size()の定義
    std::size_t my_size(){
        return size_num;
    }
};

// test用main関数
int main(){

    my_array<int, 5> ma1;
    ma1 = {0,1,2,3,4};

    using array_type = my_array<int, 5>;
    array_type::data_type int_num = 10;
    array_type::reference ref = ma1[2];
    ref = 10;
    std::size_t snum = ma1.my_size();

    for(int i = 0; i < 5; i++) std::cout << ma1[i] << " ";
    std::cout << std::endl;
    std::cout << int_num << std::endl;
    std::cout << snum << std::endl;

    return 0;
}