#include "all.h"

//  class template
template <typename Array>
struct My_array_iterator{

    //  データメンバ
    Array &data;
    std::size_t pos;

    //  コンストラクタ
    My_array_iterator(Array &data, std::size_t pos): data(data), pos(pos){
        // None
    }

    //  演算子オーバーロード
    //  配列要素へのリファレンスを返すから戻り値はArray::reference
    typename Array::reference operator *(){
        return data[pos];
    }
    //  前置演算子
    //  戻り値はイテレータへのリファレンス
    My_array_iterator & operator ++(){
        ++pos;
        return *this;       //  posを加算した上でMy_iterator_arrayのオブジェクトへのリファレンスを返す
    }
    My_array_iterator & operator --(){
        --pos;
        return *this;
    }
};

//  class template
template <typename T, std::size_t N>
struct My_array{

    //  データメンバ
    T data[N] = {};

    //  エイリアス
    using data_type = T;
    using data_size = std::size_t;
    using reference = T &;
    using const_reference = T const &;
    using iterator = My_array_iterator<My_array>;

    //  演算子オーバーロード
    reference operator [](data_size num){
        return data[num];
    }

    //  メンバ関数
    //  クラス名に()を付けてコンストラクタを呼び出した後のオブジェクトを返している
    iterator begin(){
        return iterator(*this, 0);
    }
    iterator end(){
        return iterator(*this, N);
    }
};

//  test
int main(){

    My_array<int, 3> data = {1,2,3};

    auto iter1 = data.begin();
    std::cout << *iter1 << std::endl;    // 1

    ++iter1;
    std::cout << *iter1 << std::endl;    //  2

    auto iter2 = data.end();
    --iter2;
    std::cout << *iter2 << std::endl;    // 3

    return 0;
}