#include "all.h"

//  class template
template <typename Array>
struct My_array_iterator{

    //  データメンバ
    Array &my_data;
    std::size_t pos;

    //  コンストラクタ
    My_array_iterator(Array &my_data, std::size_t pos): my_data(my_data), pos(pos){
        // None
    }


    //  演算子オーバーロード
    //  配列要素へのリファレンスを返すから戻り値はArray::reference
    typename Array::reference operator *(){
        return my_data[pos];
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
    bool operator ==(My_array_iterator const &my_data_arg){
        //  引数のデータメンバにアクセス
        return pos == my_data_arg.pos;
    }
    bool operator !=(My_array_iterator const &my_data_arg){
        //  引数のデータメンバにアクセス
        return pos != my_data_arg.pos;
    }
    bool operator <(My_array_iterator const &my_data_arg){
        //  大小比較の結果をbool値で返す
        return (pos < my_data_arg.pos);
    }
    bool operator <=(My_array_iterator const &my_data_arg){
        //  大小比較の結果をbool値で返す
        return (pos <= my_data_arg.pos);
    }
    bool operator >(My_array_iterator const &my_data_arg){
        //  大小比較の結果をbool値で返す
        return (pos > my_data_arg.pos);
    }
    bool operator >=(My_array_iterator const &my_data_arg){
        //  大小比較の結果をbool値で返す
        return (pos >= my_data_arg.pos);
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
    //  データメンバ（*this）を変更しないため関数をconstにできる
    My_array_iterator operator +(std::size_t num_arg) const{
        My_array_iterator temp = *this;     //  *thisはクラスオブジェクトへのリファレンス（つまりポインタ？）
        temp += num_arg;
        return temp;
    }
    

    //  減算代入演算子
    My_array_iterator & operator -=(std::size_t num_arg){
        pos -= num_arg;
        return *this;
    }
    //  データメンバ（*this）を変更しないため関数をconstにできる
    My_array_iterator operator -(std::size_t num_arg) const{
        //  自分自身（*this）に変更なし
        My_array_iterator temp = *this;
        temp -= num_arg;
        return temp;
    }


    //  アクセス演算子
    //  イテレータが指す実体を返す演算子なので戻り値はArray::reference
    typename Array::reference operator [](std::size_t num_arg){
        //  受け取るのはクラスオブジェクトへのリファレンスとstd::size_t
        //  既にオーバーロードした*を使用してArray::referenceを返している
        return *(*this + num_arg);
    }
};

//  class template
//  const_iteratorはイテレータの変更は可能だが参照先の変更ができないイテレータ
template <typename Array>
struct My_array_const_iterator{

    //  データメンバ(My_array_const_iterator固有の変数)
    Array const &my_data;
    std::size_t const_pos;

    //  コンストラクタ
    //  constなArrayを引数に取るイテレータ
    My_array_const_iterator(Array const &my_data, std::size_t pos): my_data(my_data), const_pos(pos){
        // None
    }

};


//  class template
template <typename T, std::size_t N>
struct My_array{

    //  データメンバ
    T my_data[N] = {};


    //  エイリアス
    using my_data_type = T;
    using my_data_size = std::size_t;
    using reference = T &;
    using const_reference = T const &;
    //  イテレータのエイリアス
    using iterator = My_array_iterator<My_array>;
    using const_iterator = My_array_const_iterator<My_array>;

    //  演算子オーバーロード
    reference operator [](my_data_size num){
        return my_data[num];
    }

    //  メンバ関数
    //  クラス名に()を付けてコンストラクタを呼び出した後のオブジェクトを返している
    iterator begin(){
        return iterator(*this, 0);
    }
    iterator end(){
        return iterator(*this, N);
    }

    //  const_iterator版
    //  constなarrayから呼び出された場合
    const_iterator beign() const{
        return const_iterator(*this, 0);
    }
    const_iterator end() const{
        return const_iterator(*this, N);
    }
    //  arrayから直接const_iteratorを呼び出す場合
    const_iterator cbegin(){
        return const_iterator(*this, 0);
    }
    const_iterator cend(){
        return const_iterator(*this, N);
    }
};


//  test
int main(){

    My_array<int, 3> my_data = {1,2,3};

    auto iter1 = my_data.begin();
    std::cout << *iter1 << std::endl;    // 1

    ++iter1;
    std::cout << *iter1 << std::endl;    //  2

    auto iter2 = my_data.end();
    --iter2;
    std::cout << *iter2 << std::endl;    // 3

    auto iter3 = my_data.begin();
    std::cout << *(iter3++) << std::endl;   //  1
    std::cout << *(iter3++) << std::endl;   //  2

    auto iter_l = my_data.begin();
    auto iter_r = my_data.begin();
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

    for(auto iter = my_data.begin(); iter != my_data.end(); ++iter) std::cout << *iter << " "s;   //  1 2 3
    std::cout << std::endl;

    auto iter4 = my_data.begin();
    iter4 += 2;
    std::cout << *iter4 << std::endl;   //  3

    auto iter5 = my_data.begin() + 1;
    std::cout << *iter5 << std::endl;   //  2

    auto iter6 = my_data.begin();
    std::cout << iter6[1] << std::endl;  //  2

    auto iter7 = my_data.begin();
    auto iter8 = my_data.end();
    std::cout << (iter7 < iter8) << std::endl;  //  true
    std::cout << (iter7 <= iter8) << std::endl;  //  true
    std::cout << (iter7 > iter8) << std::endl;  //  true
    std::cout << (iter7 >= iter8) << std::endl;  //  true

    auto iter9 = my_data.cbegin();
    //  演算子オーバーロード未実装
    std::cout << *iter9 << std::endl; 

    return 0;
}