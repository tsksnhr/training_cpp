// 演算子オーバーロード（インクリメント、デクリメント）

// 自作ヘッダファイルをインクルード
#include "all.h"

// class定義
struct TestClass{

    int a, b;

    // コンストラクタ
    TestClass(int x, int y){
        a = x;
        b = y;
    }

    // デストラクタ
    ~TestClass(){}
};

// 演算子オーバーロード(前置演算子)
// 前置演算子を評価すると演算後の値となる
TestClass operator ++(TestClass &tc){
    ++tc.a;
    ++tc.b;
    return tc;
};
TestClass operator --(TestClass &tc){
    --tc.a;
    --tc.b;
    return tc;
};

// 演算子オーバーロード(後置演算子)
// 後置演算子を評価すると演算前の値になる
TestClass operator ++(TestClass &tc, int temp){
    
    auto buf = tc;
    tc.a++;
    tc.b++;

    return buf;
}
TestClass operator --(TestClass &tc, int temp){
    
    auto buf = tc;
    tc.a--;
    tc.b--;

    return buf;
}

// test用main関数
int main(){

    TestClass tc(10, 20);

    ++tc;
    std::cout << tc.a << " " << tc.b << std::endl;      // 11 21
    --tc;
    --tc;
    std::cout << tc.a << " " << tc.b << std::endl;      // 9 19

    tc++;
    std::cout << tc.a << " " << tc.b << std::endl;      // 10 20
    tc--;
    tc--;
    std::cout << tc.a << " " << tc.b << std::endl;      // 8 18

    return 0;
}