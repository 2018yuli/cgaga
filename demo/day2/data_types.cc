#include <iostream>  // 引入输入输出流库
using namespace std;

// g++ data_types.cc -o data_types
int main() {
    // 定义一个 char 数组，大小为 10 个字符，并用 "a" 初始化。
    // 注意 "a" 是字符串常量，实际内容是 {'a','\0'}。
    // 也就是说数组前两个位置是 'a' 和字符串结束符 '\0'，剩下 8 个位置是未初始化的（值不确定）。
    char a[10] = "a";  
    
    short int s = 97;       // 短整型，值为 97
    int m = 97;             // 普通整型，值为 97
    long int n = 97;        // 长整型，值为 97
    float f = 97.0f;        // 单精度浮点数，值为 97.0
    double d = 97.0;        // 双精度浮点数，值为 97.0
    long double k = 97.0;   // 长双精度浮点数，值为 97.0
    bool b = true;          // 布尔类型，true
    wchar_t w[10] = L"a";   // 宽字符数组，初始化为 "a"

    // 输出各个变量的值
    cout << "char a[10] = \"a\" => a[0] = " << a[0] 
         << ", a[1] = " << (int)a[1] << " (\\0)" << endl;
    cout << "short int s = " << s << endl;
    cout << "int m = " << m << endl;
    cout << "long int n = " << n << endl;
    cout << "float f = " << f << endl;
    cout << "double d = " << d << endl;
    cout << "long double k = " << k << endl;
    cout << "bool b = " << b << endl;
    cout << "wchar_t w[0] = " << w[0] << endl;

    return 0;
}
