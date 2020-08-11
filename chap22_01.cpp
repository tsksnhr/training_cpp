#include "all.h"

// std::arrayの実装
struct array_int_10{

    // 配列を用いたデータメンバーの宣言
    int data_array[10];

    // []演算子の実装
    // 戻り値がreferenceでないと配列の書き換えができない
    int & operator [](std::size_t size_num){
        return data_array[size_num];
    }
};

// test用main関数
int main(){

    array_int_10 a = {0,1,2,3,4,5,6,7,8,9};
    array_int_10 b = a;

    for(int i = 0; i != 10; i++) std::cout << a.data_array[i] << " ";
    std::cout << std::endl;
    for(int i = 0; i != 10; i++) std::cout << b.data_array[i] << " ";
    std::cout << std::endl;

    b[5] = 100;
    std::cout << b[5] << std::endl;

    return 0;
}