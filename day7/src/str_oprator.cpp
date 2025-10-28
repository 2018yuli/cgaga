#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/**********************
 * C++ std::string 相关函数
 **********************/

// 打印基本信息
void showStringInfo(const string &s) {
    cout << "字符串内容: " << s << endl;
    cout << "长度: " << s.length() << endl;
}

// 比较两个字符串
void compareStrings(const string &a, const string &b) {
    if (a == b)
        cout << "字符串相等 ✅" << endl;
    else if (a < b)
        cout << "\"" << a << "\" < \"" << b << "\"" << endl;
    else
        cout << "\"" << a << "\" > \"" << b << "\"" << endl;
}

// 查找子串
void findSubstring(const string &s, const string &sub) {
    size_t pos = s.find(sub);
    if (pos != string::npos)
        cout << "子串 \"" << sub << "\" 在位置 " << pos << endl;
    else
        cout << "未找到子串 \"" << sub << "\"" << endl;
}

// 修改字符串
void modifyString(string &s) {
    if (!s.empty()) {
        // s[0] = toupper(s[0]);
        s[0] = static_cast<char>(toupper(static_cast<unsigned char>(s[0])));
        cout << "首字母大写后: " << s << endl;
    }
}

// 拼接
string joinStrings(const string &a, const string &b) {
    return a + " " + b;
}


/**********************
 * C 语言 string.h 相关函数
 **********************/

// 打印 C 字符串信息
void showCStringInfo(const char *s) {
    cout << "C字符串内容: " << s << endl;
    cout << "长度: " << strlen(s) << endl;
}

// 复制
void copyCString(char *dst, const char *src) {
    strcpy(dst, src);
    cout << "strcpy -> " << dst << endl;
}

// 拼接
void concatCString(char *dst, const char *src) {
    strcat(dst, src);
    cout << "strcat -> " << dst << endl;
}

// 比较
void compareCString(const char *a, const char *b) {
    int cmp = strcmp(a, b);
    if (cmp == 0)
        cout << "相等 ✅" << endl;
    else if (cmp < 0)
        cout << "a < b" << endl;
    else
        cout << "a > b" << endl;
}

// 查找字符与子串
void findInCString(const char *s, char ch, const char *sub) {
    const char *pch = strchr(s, ch);
    if (pch)
        cout << "字符 '" << ch << "' 出现在位置 " << (pch - s) << endl;
    else
        cout << "未找到字符 '" << ch << "'" << endl;

    const char *psub = strstr(s, sub);
    if (psub)
        cout << "子串 \"" << sub << "\" 出现在位置 " << (psub - s) << endl;
    else
        cout << "未找到子串 \"" << sub << "\"" << endl;
}


/**********************
 * 主函数
 **********************/
int main() {
    cout << "===== C++ std::string 演示 =====" << endl;

    string s1 = "hello";
    string s2 = "world";
    string s3 = joinStrings(s1, s2);

    showStringInfo(s3);
    compareStrings(s1, s2);
    findSubstring(s3, "wor");
    modifyString(s3);
    cout << "最终结果: " << s3 << endl;

    cout << "\n===== C 风格字符串演示 =====" << endl;

    char a[50] = "hello";
    char b[50] = "world";
    char c[100];

    copyCString(c, a);
    concatCString(c, " ");
    concatCString(c, b);
    showCStringInfo(c);
    compareCString(a, b);
    findInCString(c, 'w', "world");

    cout << "\n===== 结束 =====" << endl;
    return 0;
}
