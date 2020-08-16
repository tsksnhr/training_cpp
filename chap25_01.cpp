#include "all.h"

//  template
template <typename T, std::size_t N>
struct my_array{

    //  alies
    using data_type = T;
    using reference = T &;
    using const_reference = T const &;
    using data_size = std::size_t;
//    using iterator = my_array_iterator;

    //  data member
    data_type data_array[N] = {};

    //  operator overload
    reference operator [](data_size num){
        return data_array[num];
    }
};

//  template
template <typename Array>
struct my_array_iterator{

    //  data memner
    Array &data;

    //  constructor
    my_array_iterator(Array &data): data(data){
//        my_array_iterator::data = data;
    }

    //  operator overload
    //  Array is a name depend on a template and reference is a nested-name, so typename is must.
    typename Array::reference operator *(){
        return data[0];
    }
};

//  test
int main(){

    my_array<int, 5> a = {10,1,2,3,4};
    my_array_iterator<my_array<int, 5>> a_iter(a);

    std::cout << *a_iter << std::endl;

    return 0;
}