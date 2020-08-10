#include "all.h"

// classの定義
struct TestClass{

    int a;
    double b;

    void my_print(){
        std::cout << "a = " << TestClass::a << " " << "b = " << TestClass::b << std::endl;
        return; 
    }
    int my_sum(){
        return a + (int)b;
    }
};

// test用main関数
int main(){

    TestClass ts;
    ts.a = 10;
    ts.b = 12.5;
    int c{};

    ts.my_print();
    c = ts.my_sum();
    std::cout << "c = " << c;

    return 0;
}
