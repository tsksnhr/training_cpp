// preincludeしているので無くてもいいがvscodeがうるさいので記載
#include "all.h"

int main(){

    // NaN
    std::cout << std::numeric_limits<float>::quiet_NaN() << std::endl;
    std::cout << std::numeric_limits<double>::quiet_NaN() << std::endl;
    std::cout << std::numeric_limits<long double>::quiet_NaN() << std::endl;

    // 仮数部で表現できる桁数
    std::cout << std::numeric_limits<float>::digits10 << std::endl;
    std::cout << std::numeric_limits<double>::digits10 << std::endl;
    std::cout << std::numeric_limits<long double>::digits10 << std::endl;

    // 浮動小数点の1と比較できる最小の数
    std::cout << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << std::numeric_limits<long double>::epsilon() << std::endl;

    return 0;
}