#include "all.h"

int main(){

    std::array<int, 3> a = {1, 2, 3};

    //  コンパイラのwarning対策
    //  auto iter = a.begin();
    auto c_iter = a.cbegin();
    auto const citer = a.begin();
    auto const c_citer = a.cbegin();

    //  iterator
    //  iterator自体の変更も参照先の変更も可能
    for(auto iter_temp = a.begin(); iter_temp != a.end(); ++iter_temp){
        *iter_temp += 10;
        std::cout << *iter_temp << " "s;    //  11 12 13
    }
    std::cout << std::endl;

    //  const_iterator
    std::cout << *(++c_iter) << std::endl;  //  12
    //  const_iteratorでは参照先の値を変更できないのでerror
    //  *c_iter = 88;

    //  constなiterator
    //  iteratorがconstなのでerror
    //  ++citer;
    *citer = 88;
    std::cout << *citer << std::endl;       //  88

    //  constなconst_iterator
    //  iteratoの変更も参照先の変更も不可
    std::cout << *c_citer << std::endl;       //  88
    //  *c_citer = 99;
    //  ++c_citer;

    return 0;
}