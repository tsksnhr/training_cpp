#include "all.h"

// classの宣言
struct TestClass{

    int a = 10;
    double b = 20;

    // 引数を受け取る関数
    void get_num(int a_, double b_){
        a = a_;
        b = b_;
    }
    // 引数を受け取る関数（誤り）
    void ivd_get_num(int a, double b){
        a = a;
        b = b;
    }

    int int_sum(){
        return a + (int)b;
    }
};

//　test用main関数
int main(){

    TestClass ts;

    // メンバ変数に値を代入
    ts.a = 10;
    ts.b = 20;
    std::cout << ts.int_sum() << std::endl;     // 10 + 20

    // aとbが書き換わる
    ts.get_num(50, 60);
    std::cout << ts.int_sum() << std::endl;     // 50 + 60

    // 変数スコープの関係でaとbが書き換わらない
    ts.ivd_get_num(500, 600);
    std::cout << ts.int_sum() << std::endl;     // 50 + 60

    return 0;
}