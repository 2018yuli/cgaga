#include <iostream>
#include <cstring>
using namespace std;

// 1️⃣ 基本定义与打印
void basic_define() {
    cout << "=== 1️⃣ 基本定义与打印 ===" << endl;
    char str1[11] = "helloworld";  // 多预留 1 位给 '\0'
    cout << "str1 内容: " << str1 << endl;
    cout << "sizeof(str1): " << sizeof(str1) << endl;  // 11（包含 '\0'）
    cout << endl;
}

// 2️⃣ 未预留 '\0' 的错误示例
void no_null_terminator() {
    cout << "=== 2️⃣ 未预留 '\\0' 的错误示例 ===" << endl;
    // char str2[10] = "helloworld";  // ❌ 未预留 '\0'
    char str2[11] = "helloworld";
    cout << "str2 内容(未定义行为): " << str2 << endl;
    cout << endl;
}

// 3️⃣ 手动添加字符串结束符
void manual_null_terminator() {
    cout << "=== 3️⃣ 手动添加字符串结束符 ===" << endl;
    char str3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "str3 内容: " << str3 << endl;
    cout << endl;
}

// 4️⃣ 输入字符串（注意空格）
void input_string() {
    cout << "=== 4️⃣ 输入字符串（不含空格） ===" << endl;
    char name[20];
    cout << "请输入名字: ";
    cin >> name;  // 遇空格或换行结束
    cout << "你好, " << name << "!" << endl;
    cout << endl;
}

// 5️⃣ 使用 cin.getline() 读取整行（包含空格）
void input_line() {
    cout << "=== 5️⃣ 使用 cin.getline() 读取整行 ===" << endl;
    char sentence[50];
    cout << "请输入一句话: ";
    cin.ignore();  // 忽略上一次输入残留的换行
    cin.getline(sentence, 50);
    cout << "你输入的是: " << sentence << endl;
    cout << endl;
}

// 6️⃣ 使用 <cstring> 的常用函数
void cstring_functions() {
    cout << "=== 6️⃣ <cstring> 常用函数 ===" << endl;
    char a[20] = "Hello";
    char b[20] = "World";

    cout << "strlen(a): " << strlen(a) << endl; // 5
    strcat(a, b);   // 拼接字符串
    cout << "拼接后 a: " << a << endl;
    cout << "strcmp(a, b): " << strcmp(a, b) << endl; // 比较字符串
    strcpy(b, "C++");
    cout << "复制后 b: " << b << endl;
    cout << endl;
}

// 7️⃣ '\0' 截断现象
void null_char_truncation() {
    cout << "=== 7️⃣ '\\0' 截断现象 ===" << endl;
    char str[] = "Hel\0lo";
    cout << "strlen(str): " << strlen(str) << endl; // 3
    cout << "sizeof(str): " << sizeof(str) << endl; // 7
    cout << "直接输出: " << str << endl;            // 只输出 "Hel"
    cout << endl;
}

// 8️⃣ 遍历字符数组
void traverse_char_array() {
    cout << "=== 8️⃣ 遍历字符数组 ===" << endl;
    char str[] = "Hello";
    cout << "逐个字符: ";
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << "[" << i << "]=" << str[i] << " ";
    }
    cout << endl << endl;
}

// 9️⃣ 修改字符内容
void modify_char_array() {
    cout << "=== 9️⃣ 修改字符内容 ===" << endl;
    char str[] = "Hello";
    str[0] = 'Y';
    cout << "修改后: " << str << endl;
    cout << endl;
}

// 🔟 字符数组 vs 指针
void array_vs_pointer() {
    cout << "=== 🔟 字符数组 vs 字符指针 ===" << endl;
    char arr[] = "Hello";       // 可修改
    const char* ptr = "World";  // 字符常量，不可修改

    cout << "arr: " << arr << ", ptr: " << ptr << endl;
    arr[0] = 'Y';               // ✅
    // ptr[0] = 'M';            // ❌ 修改常量字符串会崩溃
    cout << "修改后 arr: " << arr << ", ptr: " << ptr << endl;
    cout << endl;
}

int main() {
    basic_define();
    no_null_terminator();
    manual_null_terminator();
    input_string();
    input_line();
    cstring_functions();
    null_char_truncation();
    traverse_char_array();
    modify_char_array();
    array_vs_pointer();
    /*
    char c1 = 0;    // 0x00
    char c2 = '\0'; // 0x00
    char c3 = '0';  // 0x30
    */
    return 0;
}
