#include <iostream>
#include <string>
#include <algorithm>   // transform, reverse
#include <cctype>      // toupper, tolower
#include <sstream>     // stringstream
#include <iomanip>     // setw, setfill

using namespace std;

/******************************************************
 * 打印字符串信息
 ******************************************************/
void printInfo(const string &label, const string &s) {
    cout << "[" << label << "] 内容: \"" << s
         << "\" | 长度: " << s.length()
         << " | 是否为空: " << (s.empty() ? "是" : "否") << endl;
}

/******************************************************
 * 基本创建与拼接
 ******************************************************/
void demo_create_concat() {
    cout << "\n===== 1️⃣ 创建与拼接 =====" << endl;

    string s1("Hello");
    string s2 = "World";
    string s4 string("sansan");
    string s3 = s1 + " " + s2 + "!";

    printInfo("s1", s1);
    printInfo("s2", s2);
    printInfo("拼接结果 s3", s3);
    printInfo("s4", s4);
}

/******************************************************
 * 比较与判断
 ******************************************************/
void demo_compare() {
    cout << "\n===== 2️⃣ 比较与判断 =====" << endl;

    string a = "apple";
    string b = "banana";

    cout << "a == b ? " << (a == b ? "true" : "false") << endl;
    cout << "a < b ? " << (a < b ? "true" : "false") << " （按字典序比较）" << endl;
    cout << "a.compare(b) = " << a.compare(b) << endl; // <0 表示 a<b
}

/******************************************************
 * 查找、子串、替换
 ******************************************************/
void demo_find_replace() {
    cout << "\n===== 3️⃣ 查找、子串、替换 =====" << endl;

    string text = "The quick brown fox jumps over the lazy dog.";
    printInfo("原始文本", text);

    // 查找子串
    size_t pos = text.find("fox");
    if (pos != string::npos)
        cout << "找到 \"fox\"，位置: " << pos << endl;

    // 提取子串
    string sub = text.substr(pos, 3);
    cout << "提取的子串: " << sub << endl;

    // 替换
    text.replace(pos, 3, "cat");
    cout << "替换后: " << text << endl;
}

/******************************************************
 * 插入与删除
 ******************************************************/
void demo_insert_erase() {
    cout << "\n===== 4️⃣ 插入与删除 =====" << endl;

    string s = "I coffee.";
    printInfo("原始", s);

    // 插入字符串
    s.insert(2, "love ");
    cout << "插入后: " << s << endl;

    // 删除部分字符
    s.erase(2, 5);
    cout << "删除后: " << s << endl;
}

/******************************************************
 * 大小写转换与反转
 ******************************************************/
void demo_case_reverse() {
    cout << "\n===== 5️⃣ 大小写转换与反转 =====" << endl;

    string s = "Hello World";
    printInfo("原始", s);

    // 转大写
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c){ return static_cast<char>(toupper(c)); });
    cout << "大写: " << s << endl;

    // 转小写
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c){ return static_cast<char>(tolower(c)); });
    cout << "小写: " << s << endl;

    // 字符串反转
    reverse(s.begin(), s.end());
    cout << "反转: " << s << endl;
}

/******************************************************
 * 遍历与访问
 ******************************************************/
void demo_iteration() {
    cout << "\n===== 6️⃣ 遍历与访问 =====" << endl;

    string s = "ABCDE";

    cout << "下标访问: ";
    for (size_t i = 0; i < s.size(); ++i)
        cout << s[i] << " ";
    cout << endl;

    cout << "范围for访问: ";
    for (char c : s)
        cout << c << " ";
    cout << endl;

    cout << "首字符: " << s.front() << ", 末字符: " << s.back() << endl;
}

/******************************************************
 * 去空格、trim
 ******************************************************/
string trim(const string &str) {
    auto start = str.find_first_not_of(" \t\n\r");
    auto end = str.find_last_not_of(" \t\n\r");
    if (start == string::npos) return "";
    return str.substr(start, end - start + 1);
}

void demo_trim() {
    cout << "\n===== 7️⃣ 去空格 Trim =====" << endl;

    string s = "   hello world   \n";
    printInfo("原始", s);
    cout << "去空格后: \"" << trim(s) << "\"" << endl;
}

/******************************************************
 * 字符串与数字转换
 ******************************************************/
void demo_conversion() {
    cout << "\n===== 8️⃣ 字符串与数字转换 =====" << endl;

    string s = "123";
    int num = stoi(s);
    double pi = stod("3.14159");

    cout << "stoi(\"123\") -> " << num << endl;
    cout << "stod(\"3.14159\") -> " << pi << endl;

    string s2 = to_string(2025);
    cout << "to_string(2025) -> \"" << s2 << "\"" << endl;
}

/******************************************************
 * 使用 stringstream 进行格式化与拼接
 ******************************************************/
void demo_stringstream() {
    cout << "\n===== 9️⃣ stringstream 拼接与格式化 =====" << endl;

    stringstream ss;
    ss << "Pi ≈ " << fixed << setprecision(2) << 3.14159 << ", Year = " << 2025;
    string result = ss.str();

    cout << "stringstream 输出: " << result << endl;
}

/******************************************************
 * 输入与安全读取
 ******************************************************/
void demo_input() {
    cout << "\n===== 🔟 输入与 getline =====" << endl;

    string name;
    cout << "请输入姓名（可包含空格）: ";
    getline(cin, name);
    cout << "你好, " << name << "!" << endl;
}

/******************************************************
 * 主函数
 ******************************************************/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    demo_create_concat();
    demo_compare();
    demo_find_replace();
    demo_insert_erase();
    demo_case_reverse();
    demo_iteration();
    demo_trim();
    demo_conversion();
    demo_stringstream();

    // ✅ 最后一个演示需要手动输入
    demo_input();

    cout << "\n=== 🌟 Demo 结束 ===" << endl;

    // 转换为 c 字符串
    const char *c_str = "Hello, C++!".c_str();
    cout << "C 字符串: " << c_str << endl;

    return 0;
}
