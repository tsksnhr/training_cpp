#include "all.h"

// class定義
struct TestClass{

    int a;

    // コンストラクタ
    TestClass(int x){
        a = x;
    }

    // デストラクタ
    ~TestClass(){}

    // class内の演算子オーバーロード
    TestClass operator +(TestClass tc){
        return TestClass{ a + tc.a };
    }
    // classない演算子オーバーロードで前置演算子を実装するには・・・？
    TestClass & operator ++(){
        ++a;
        return TestClass{ a };
    }
    TestClass operator ++(int invalid_num){
        auto temp = a;
        ++a;
        return TestClass{ temp };
    }
};

// test用main関数
int main(){

    TestClass tc1(10);
    TestClass tc2(20);

    // 演算子のtest
    std::cout << tc1.a + tc2.a << std::endl;    // 30
    std::cout << ++tc1.a << std::endl;          // 11
    std::cout << tc1.a++ << std::endl;          // 11
    std::cout << tc1.a << std::endl;            // 12

    return 0;
}
