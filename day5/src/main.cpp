#include <iostream>

using namespace std;


// 字符串截断
void char_truncate()
{
    char c1 = 'yes'; // 截断
    std::cout << c1 << std::endl;   // s
}

void char_sequence()
{
    const char* slash = "/";
    std::cout << slash << std::endl;   // /
}

void char_sequence_test()
{
    const char* slash = "yes";
    std::cout << slash << std::endl;   // /
}

/////////////////////////////////// cxx string ///////////////////////////////////

# include <string>

void string_truncate()
{
    string s1(1, 'yes');    // s1 == "s"
    cout << s1 << endl;   // s

    string s2("/");
    cout << s2 << endl;   // /

    // 在 C++11 之后，对于像 string s3 = "/"; 这样的拷贝初始化
    // 编译器通常会省略掉创建临时对象和进行拷贝的步骤
    // 直接调用构造函数来创建 s3，使其行为与直接初始化完全相同
    string s3 = "yes";
    cout << s3 << endl;   // yes
}


int main(int argc, char *argv[])
{
    char_truncate();
    char_sequence();
    char_sequence_test();
    string_truncate();
}

