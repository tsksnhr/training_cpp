#include "all.h"

template <typename T, std::size_t size>
struct my_array{

    using data_type = T;
    using reference = T &;
    using const_reference = T const &;

    //  data member
    data_type data_array[size] = {};

    //  operator overload
    reference operator [](std::size_t snum){
        return data_array[snum];
    }

    // member function
    reference front(){
        return data_array[0];
    }
    const_reference front() const{
        return data_array[0];
    }
    reference back(){
        return data_array[size-1];
    }
    const_reference back() const{
        return data_array[size-1];
    }
};

//  test
int main(){

//    my_array<int, 5> a;
    my_array<int, 5> a = {10, 11, 12, 13, 14};
    my_array<int, 5> const ca = {0, 1, 2, 3, 4};

    std::cout << a.front() << std::endl;
    std::cout << ca.front() << std::endl;
    std::cout << a.back() << std::endl;
    std::cout << ca.back() << std::endl;

    return 0;
}