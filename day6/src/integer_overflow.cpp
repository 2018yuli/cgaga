#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

// 安全加法函数：检测溢出
int safeAdd(int a, int b) {
    if ((b > 0 && a > numeric_limits<int>::max() - b) ||
        (b < 0 && a < numeric_limits<int>::min() - b)) {
        throw overflow_error("Integer overflow detected!");
    }
    return a + b;
}

int main() {
    cout << "===== 未检测溢出 =====" << endl;
    {
        int a = numeric_limits<int>::max();
        int b = 1;
        int c = a + b;  // 溢出（未定义行为）
        cout << "a=" << a << ", b=" << b << ", a+b=" << c << endl;
    }

    cout << "\n===== 检测并抛出异常 =====" << endl;
    {
        int a = numeric_limits<int>::max();
        int b = 1;
        try {
            int c = safeAdd(a, b);
            cout << "safeAdd(a,b)=" << c << endl;
        } catch (const overflow_error& e) {
            cout << "异常: " << e.what() << endl;
        }
    }

    cout << "\n===== 检测负数溢出 =====" << endl;
    {
        int a = numeric_limits<int>::min();
        int b = -1;
        try {
            int c = safeAdd(a, b);
            cout << "safeAdd(a,b)=" << c << endl;
        } catch (const overflow_error& e) {
            cout << "异常: " << e.what() << endl;
        }
    }

    return 0;
}
