// 演算子オーバーロード

#include "all.h"

// class定義
struct Fraction{

    int num;
    int demon;

    // コンストラクタ
    Fraction(int num_, int demon_){
        num = num_;
        demon = demon_;
    }

    // デストラクタ
    ~Fraction(){}
};

// 演算子オーバーロード
Fraction operator +(Fraction l, Fraction r){
    
    if(l.demon == r.demon){
        return Fraction(l.num + r.num, l.demon);
    }
    else{
        return Fraction(l.num * r.demon + l.demon * r.num, l.demon * r.demon);
    }
}
Fraction operator -(Fraction l, Fraction r){
    
    if(l.demon == r.demon){
        return Fraction(l.num - r.num, l.demon);
    }
    else{
        return Fraction(l.num * r.demon - l.demon * r.num, l.demon * r.demon);
    }
}
Fraction operator *(Fraction l, Fraction r){
    
    return Fraction(l.num * r.num, l.demon * r.demon);
}
Fraction operator /(Fraction l, Fraction r){
    
    return Fraction(l.num * r.demon, l.demon * r.num);
}

// test用main関数
int main(){

    Fraction value1(10, 20);
    Fraction value2(40, 20);
    Fraction value3(5, 50);

    Fraction ans = value1 + value2;
    std::cout << ans.num << " " << ans.demon << std::endl;      // 50 20

    ans = value1 - value2;
    std::cout << ans.num << " " << ans.demon << std::endl;      // -30 20

    ans = value1 + value3;
    std::cout << ans.num << " " << ans.demon << std::endl;      // 600 1000

    ans = value1 - value3;
    std::cout << ans.num << " " << ans.demon << std::endl;      // 400 1000

    ans = value1 * value2;
    std::cout << ans.num << " " << ans.demon << std::endl;      // 400 400

    ans = value1 / value2;
    std::cout << ans.num << " " << ans.demon << std::endl;      // 200 800

    return 0;
}