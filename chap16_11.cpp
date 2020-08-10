#include "all.h"

// 判定用関数の実装
bool pred1(double a, double b){
    
    int fa = std::floor(a);
    int fb = std::floor(b);

    if(fa == fb) return true;
    return false;
}


// 自作equalの実装
auto my_equal(auto first1, auto last1, auto first2, auto last2){

    auto size1 = last1 - first1;
    auto size2 = last2 - first1;

    if(size1 == size2) return false;

    for(auto iter1 = first1, iter2 = first2; iter1 != last1; iter1++, iter2++){
        if(*iter1 != *iter2) return false;
    }

    return true;
}
auto my_equal(auto first1, auto last1, auto first2, auto last2, auto pred){

    auto size1 = last1 - first1;
    auto size2 = last2 - first1;

    if(size1 == size2) return false;

    for(auto iter1 = first1, iter2 = first2; iter1 != last1; iter1++, iter2++){
        if(!pred(*iter1, *iter2)) return false;
    }

    return true;
}

// test用main関数
int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> w = {1, 2, 3, 4, 5};
    std::vector<double> x = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<double> y = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<double> z = {1.1, 2.2, 10.3, 4.4, 5.5};

    std::cout << std::boolalpha;
    std::cout << my_equal(std::begin(v), std::end(v), std::begin(w), std::end(w)) << std::endl;     //true
    std::cout << my_equal(std::begin(x), std::end(x), std::begin(y), std::end(y), pred1) << std::endl;     //true
    std::cout << my_equal(std::begin(x), std::end(x), std::begin(z), std::end(z), pred1) << std::endl;     //false

    return 0;
}