#include <ios>
#include <iostream>

using namespace std;

#define PI 3.1415926
const double PI_CONST = 3.1415926;

void basic_types()
{
    char a[10] = "a";
    int b = 0x1;
    int c = 0X2;
    // 8 进制
    int d = 011;
    // C++14 2进制
    int e = 0b11;
    // 无符号数
    int f = 215u; 
    bool g = true;
    std::wstring s = L"Hello world!";
    
    std::wcout << std::boolalpha;  // 让 bool 打印 true/false

    // 运行结果：Hello world! 3.14159 3.14159 1 2 9 3 215 true Hello world!
    std::wcout << "Hello world! "
              << PI << " "
              << PI_CONST << " "
              << b << " "
              << c << " "
              << d << " "
              << e << " "
              << f << " "
              << g << " "
              << s << " "
              << std::endl;
}

int B2T(int num)
{
    return (int)(num);
}
unsigned B2U(unsigned int num)
{
    return (unsigned int)(num);
}

void validate_bool()
{
    wcout << B2T(0X00000000) << endl;   // 0
    wcout << B2T(0XFFFFFFFF) << endl;   // -1
    wcout << B2T(0x80000000) << endl;   // -2147483648
    wcout << B2T(0x7FFFFFFF) << endl;   // 2147483647
    wcout << endl;                          // 换行
    wcout << B2U(0x00000000) << endl;   // 0
    wcout << B2U(0xFFFFFFFF) << endl;   // 4294967295
    wcout << B2U(0x80000000) << endl;   // 2147483648
    wcout << B2U(0x7FFFFFFF) << endl;   // 2147483647
}

int main(int argc, char *argv[])
{
    basic_types();
    validate_bool();
    return 0;
}

