#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/******************************************************
 * ⚠️ 不安全的 C 字符串拷贝与拼接示例
 ******************************************************/
void unsafeCopyAndConcat()
{
    cout << "\n=== ⚠️ 不安全的 strcpy / strcat 示例 ===" << endl;

    char smallBuffer[10];  // 缓冲区很小（只 10 字节）
    const char *largeText = "HelloWorld!"; // 11 个字符 + '\0' 共 12 字节

    // strcpy 不会检查目标缓冲区大小
    // 若字符串过长，内存将被覆盖（造成崩溃或安全漏洞）
    cout << "尝试 strcpy..." << endl;
    strcpy(smallBuffer, largeText); // ⚠️ 溢出！

    cout << "smallBuffer 内容: " << smallBuffer << endl;

    // strcat 同样危险，它只是简单地拼接，不检查长度
    char text1[20] = "Hello";
    char text2[20] = "World!World!"; // 太长也会溢出

    cout << "尝试 strcat..." << endl;
    strcat(text1, text2); // ⚠️ 若 text2 过大，会覆盖内存
    cout << "拼接结果: " << text1 << endl;
}

/******************************************************
 * ✅ 安全版本 strcpy_s / strcat_s 演示
 * 在 Linux 下可用 strncpy / strncat 模拟
 ******************************************************/
void safeCopyAndConcat()
{
    cout << "\n=== ✅ 安全的字符串操作示例 ===" << endl;

    char safeBuffer[20];
    const char *text = "HelloWorld!";

#if defined(_MSC_VER)
    // ✅ Windows (MSVC) 下可直接使用 strcpy_s / strcat_s
    strcpy_s(safeBuffer, sizeof(safeBuffer), text);
#else
    // ✅ Linux 没有 strcpy_s，可用 strncpy + 手动补 '\0' 实现
    strncpy(safeBuffer, text, sizeof(safeBuffer) - 1);
    safeBuffer[sizeof(safeBuffer) - 1] = '\0';
#endif

    cout << "安全拷贝结果: " << safeBuffer << endl;

    // 拼接操作
    const char *suffix = "_OK";

#if defined(_MSC_VER)
    strcat_s(safeBuffer, sizeof(safeBuffer), suffix);
#else
    strncat(safeBuffer, suffix, sizeof(safeBuffer) - strlen(safeBuffer) - 1);
#endif

    cout << "安全拼接结果: " << safeBuffer << endl;
}

/******************************************************
 * ✅ 主函数入口
 ******************************************************/
int main()
{
    cout << "=== 字符串内存安全演示 ===" << endl;

    try
    {
        unsafeCopyAndConcat(); // ⚠️ 展示危险用法
    }
    catch (...)
    {
        cout << "捕获异常（可能的缓冲区溢出）" << endl;
    }

    safeCopyAndConcat(); // ✅ 安全做法
    cout << "\n=== 演示结束 ===" << endl;

    return 0;
}
