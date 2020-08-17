#include "all.h"

//  template
struct My_int{

    int data = {};

    My_int & func(){
        return *this;
    }
};

//  test
int main(){

    My_int a;

    a.data = 10;
    std::cout << a.data << std::endl;

    //  a.func()でMy_intのオブジェクト（ここではa）へのリファレンスが返される
    //  リファレンス経由でデータメンバにアクセスしている？
    a.func().data = 100;
    std::cout << a.data << std::endl;

    return 0;
}