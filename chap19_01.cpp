#include "all.h"

// classの宣言
struct TestClass{

    int a;
    double b;

    // コンストラクタ
    TestClass(int a, double b){
        TestClass::a = a;
        TestClass::b = b;
        std::cout << "Constructed :"s << a << " " << "Constructed :"s << b << std::endl; 
    }

    // デストラクタ
    ~TestClass(){
        std::cout << "Denstructed :"s << a << " " << "Constructed :"s << b << std::endl;
    }
};

// test用main関数
int main(){

    TestClass ts1(10, 12.3);
    {
        TestClass ts2(20, 45.6);
    }
    TestClass ts3(30, 78.9);

    return 0;
}