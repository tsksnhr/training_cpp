//  テンプレート付きクラスの前方宣言はどうやるんだ？
#include "all.h"

//  template
template <typename Array>
struct my_array_iterator{

    //  data member
    Array &data;

    //  constructor
    //  データメンバに対する特別な文法を使用している
    my_array_iterator(Array &data): data(data){

    }

    //  戻り値は配列の先頭要素へのリファレンス
    //  Arrayがtemplate依存、referenceがネストされた型名なのでreferenceが必要
    typename Array::reference operator *(){
        return data[0];
    }
};

//  template
template <typename T, std::size_t N>
struct my_array{

    //  data member
    T data[N];

    //  エイリアス
    using data_type = T;
    using reference = T &;
    using const_reference = T const &;
    using data_size = std::size_t;
    //  イテレータに対するエイリアス
    //  my_array_iteratorが自作classなので、my_array_iteratorの定義か宣言がこのエイリアスより上に必要
    using iterator = my_array_iterator<my_array>;

    //  operator overload
    reference operator [](data_size num){
        return data[num];
    }

    //  function overload
    iterator begin(){
        //  *thisはクラスオブジェクトへのポインタを返す
        //  クラス名に()か{}を付けることで、左記クラスのコンストラクタを呼び出した結果を得る
        return iterator(*this);
    }
};

//  test
int main(){

    my_array<int, 3> a = {100,101,102};
    my_array_iterator<my_array<int, 3>> a_iter(a);

    auto iter = a.begin();
    std::cout << *iter << std::endl;

    return 0;
}