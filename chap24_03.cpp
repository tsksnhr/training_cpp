// constで宣言したメンバ関数の扱い

#include "all.h"

// class宣言
struct TestClass{

    int a{};

    int mul(int x){
        return a*x;
    }
    int cmul(int const x){
        return a*x;
    }
    void nofunc(){
        std::cout << "called\n"s; 
    }
    void c_nofunc() const{
        std::cout << "called\n"s;
    }

};

// test
int main(){

    TestClass tc;
    tc.a = 10;
    std::cout << tc.mul(10) << "\n";
    std::cout << tc.cmul(10) << "\n";

    TestClass const c_tc;
    
    // constなクラス変数に対してメンバ関数を呼び出そうとしてるためエラー
    //c_tc.nofunc();
    // メンバ関数もconstなのでok
    c_tc.c_nofunc();

    return 0;
}