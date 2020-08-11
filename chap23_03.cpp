#include "all.h"

// class template
template <typename tn, std::size_t snum>

// classの定義
struct my_array{

    // snumはclass templateで定義したsize_t型を意味する
    tn data[snum];

    // 引数に取るのはsize_t型の変数
    tn & operator [](std::size_t s){
        return data[s];
    }
};

// test用main関数
int main(){

    // class templateに沿ったarrayの定義
    my_array<int, 10> a;

    // なんらかの引数を取ることを期待したクラス定義に沿わないためエラー
//    my_array b;

    a[3] = 2;
    std::cout << a[3] << std::endl;

    return 0;
}