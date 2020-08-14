// my_arrayの[]演算子をconstに対応させる

#include "all.h"

// template
template <typename T, std::size_t size_num>

// class
struct my_array{

    // alias
    using data_type = T;
    using reference = T &;
    using const_reference = T const &;

    // 配列定義
    data_type data[size_num];

    // 演算子オーバーロード
    reference operator [](std::size_t snum){
        return data[snum];
    }
    const_reference operator [](std::size_t snum) const{
        return data[snum];
    }

    // コンストラクタ
    my_array(){
        for(std::size_t s = 0; s < size_num; s++){
            data[s] = s;
        }        
    }

    // 関数定義
    std::size_t my_size(){
        return size_num;
    }

    // 内容を表示する関数
    void my_print_array(my_array arr){
        for(std::size_t s = 0; s < size_num; s++){
            std::cout << data[s] << " ";
        }
        std::cout << std::endl;
    }
};

// test
int main(){

    my_array<int, 5> ma;
    my_array<int, 5> const c_ma;

    std::cout << ma[2] << std::endl;
    std::cout << c_ma[2] << std::endl;

    ma.my_print_array(ma);
 
    return 0;
}