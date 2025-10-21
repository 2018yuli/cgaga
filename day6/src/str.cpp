#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// ==========================================================
// 🧩 C 风格字符串：strlen 与 sizeof 对比
// ==========================================================
void c_str_problem() 
{
    cout << "=== C 字符串基础对比 ===" << endl;

    char str1[] = "Hello";
    cout << "[str1] 内容: " << str1 << endl;
    cout << "strlen(str1): " << strlen(str1) << "   // 实际长度，不含 '\\0'" << endl;
    cout << "sizeof(str1): " << sizeof(str1) << "   // 数组总字节数，包含 '\\0'" << endl;
    cout << endl;

    // 注意：二进制数据或含 '\0' 的内容不能用字符串函数处理
    char strs[] = "Hel\0lo";
    cout << "[strs] 内容: " << "Hel\\0lo" << "   // 字符串中显式包含 '\\0'" << endl;
    cout << "strlen(strs): " << strlen(strs) << "   // 遇 '\\0' 停止" << endl;
    cout << "sizeof(strs): " << sizeof(strs) << "   // 实际数组长度" << endl;
    cout << endl;
}

// ==========================================================
// 🧩 C 风格字符串拼接
// ==========================================================
void c_str_concat()
{
    cout << "=== C 字符串拼接 ===" << endl;

    char str3[30] = "stringA";
    char str4[]   = "stringB";

    strcat(str3, str4); // 拼接字符串
    cout << "[str3] 内容: " << str3 << endl;
    cout << "strlen(str3): " << strlen(str3) << "   // 拼接后字符串长度" << endl;
    cout << "sizeof(str3): " << sizeof(str3) << "   // 分配的缓冲区大小" << endl;
    cout << endl;
}

// ==========================================================
// 🧩 C++ string 类
// ==========================================================
void cpp_str()
{
    cout << "=== C++ string 拼接 ===" << endl;

    string str5 = "stringA";
    string str6 = "stringB";
    str5 += str6;

    cout << "[str5] 内容: " << str5 << endl;
    cout << "str5.length(): "   << str5.length()   << endl;
    cout << "str5.capacity(): " << str5.capacity() << "   // 分配的内存，不等于长度" << endl;
    cout << "sizeof(str5): "    << sizeof(str5)    << "   // string 对象本身的大小" << endl;
    cout << endl;
}

// ==========================================================
// 🧩 C++ string 的 '\0' 行为
// ==========================================================
void cpp_str_problem()
{
    cout << "=== C++ string 中的 '\\0' 行为 ===" << endl;

    string str5 = "stringA\0stringB"; // 字符串字面量在 '\0' 后仍有内容
    cout << "[str5] 内容: " << str5 << endl;
    cout << "str5.length(): "   << str5.length()   << endl;
    cout << "str5.capacity(): " << str5.capacity() << endl;
    cout << "sizeof(str5): "    << sizeof(str5)    << endl;
    cout << endl;
}

// ==========================================================
// 🧩 主函数入口
// ==========================================================
int main()
{
    c_str_problem();
    c_str_concat();

    cout << "=== Testing C++ string ===" << endl;
    cpp_str();
    cpp_str_problem();

    return 0;
}
