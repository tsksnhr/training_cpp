#include "all.h"

//  template
template <typename A, typename B, typename C>
struct TestClass{

    //  TestClassがテンプレートを使うクラス、かつ、TestClassの中でTestClassを使っている
    //  TestClass tc<A, B, C>と同じ
    TestClass tc;
};

//  test
int main(){

    return 0;
}