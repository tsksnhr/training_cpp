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
    //  後置演算子
    //  イテレータは加算されるが式を評価すると加算する前の値となる
    My_array_iterator operator ++(int dummy){
        //  tempにthisポインタの実体をコピー
        My_array_iterator temp = *this;
        ++*this;
        return temp;
    }
    My_array_iterator operator --(int dummy){
        //  tempにthisポインタの実体をコピー
        My_array_iterator temp = *this;
        --*this;
        return temp;
    }

    //  比較演算子
    //  イテレータとイテレータを比較する、戻り値はbool値
    //  引数をconstなリファレンスとする理由は、不要なコピーを防ぐため
    bool operator ==(My_array_iterator const &data_arg){
        //  引数のデータメンバにアクセス
        return pos == data_arg.pos;
    }
    bool operator !=(My_array_iterator const &data_arg){
        //  引数のデータメンバにアクセス
        return pos != data_arg.pos;
    }

    //  イテレータに対する加算代入演算子
    //  イテレータに対する値の書き換えを実施するため、戻り値はmy_array_iterator &になる
    //  *で実体にアクセスできるイテレータを返す必要があるため、戻り値は*thisを使う
    My_array_iterator & operator +=(std::size_t num_arg){
        //  My_array_iteratorのメンバ変数であるposに対して加算を実施する
        pos += num_arg;
        return *this;
    }
    //  加算演算子
    //  メンバ関数として演算子をオーバーロードした場合、最初のオペランドはクラスオブジェクト、2個目のオブジェクトは第一引数
    My_array_iterator operator +(std::size_t num_arg){
        My_array_iterator temp = *this;     //  *thisはクラスオブジェクトへのリファレンス（つまりポインタ？）
        temp += num_arg;
        return temp;
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

    auto iter3 = data.begin();
    std::cout << *(iter3++) << std::endl;   //  1
    std::cout << *(iter3++) << std::endl;   //  2

    auto iter_l = data.begin();
    auto iter_r = data.begin();
    std::cout << std::boolalpha;
    bool flg;
    flg = (iter_l == iter_r);
    std::cout << flg << std::endl;      //  true
    flg = (iter_l != iter_r);
    std::cout << flg << std::endl;      //  false
    ++iter_l;
    flg = (iter_l == iter_r);
    std::cout << flg << std::endl;      //  false
    flg = (iter_l != iter_r);
    std::cout << flg << std::endl;      //  true

    for(auto iter = data.begin(); iter != data.end(); ++iter) std::cout << *iter << " "s;
    std::cout << std::endl;

    auto iter4 = data.begin();
    iter4 += 2;
    std::cout << *iter4 << std::endl;   //  3

    auto iter5 = data.begin() + 1;
    std::cout << *iter5 << std::endl;   //  2

    return 0;
}