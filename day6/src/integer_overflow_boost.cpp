#include <iostream>
#include <boost/safe_numerics/safe_integer.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <limits>

using namespace std;
using namespace boost::safe_numerics;
using namespace boost::multiprecision;

/*
grep "#define BOOST_LIB_VERSION" /usr/include/boost/version.hpp
sudo apt update
sudo apt install libboost-all-dev
*/
int main() {
    cout << "===== Boost.SafeNumerics 整型溢出检测 =====" << endl;

    try {
        safe<int> a = numeric_limits<int>::max();
        safe<int> b = 1;

        auto c = a + b;  // 自动检测溢出
        cout << "结果: " << c << endl; // 不会执行到这里
    } catch (const std::exception& e) {
        cout << "捕获异常: " << e.what() << endl;
    }

    try {
        safe<int> x = numeric_limits<int>::min();
        safe<int> y = -1;

        auto z = x + y;  // 负溢出检测
        cout << "结果: " << z << endl;
    } catch (const std::exception& e) {
        cout << "捕获异常: " << e.what() << endl;
    }

    cout << "\n cpp_int ≈ Java 的 BigInteger =====" << endl;
    cout << "\n===== 超大数计算 =====" << endl;
    cpp_int big = cpp_int(1);
    for (int i = 0; i < 200; ++i) {
        big *= 2;
    }
    cout << "2^200 = " << big << endl;

    return 0;
}
