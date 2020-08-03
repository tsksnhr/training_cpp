#include "all.h"

// ラムダ式による関数定義
auto func1 = [](int a){std::cout << a*a << std::endl;};
auto func2 = [](int a){std::cout << a*a*a << std::endl;};
auto func3 = [](int a){std::cout << ((double)a)/2.0 << std::endl;};

// 自作for_eachの定義
auto my_for_each(auto first, auto last, auto func){

    // iterでループ
    for(auto iter = first; iter != last; iter++){

        // funcをiterの実体に対して作用させる
        func(*iter);
    }
}

int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};

    std::cerr << " func1 " << std::endl;
    my_for_each(std::begin(v), std::end(v), func1);
    std::cerr << " func2 " << std::endl;
    my_for_each(std::begin(v), std::end(v), func2);
    std::cerr << " func3 " << std::endl;
    my_for_each(std::begin(v), std::end(v), func3);

    return 0;
}