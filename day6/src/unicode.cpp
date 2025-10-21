#include <iostream>
#include <string>
#include <cstring>
#include <codecvt>   // C++11 提供的编码转换（已弃用但仍可演示）
#include <locale>

using namespace std;

int main() {
    /*
    UTF-8	    可变长度（1–4 字节）	    英文 1B，中文 3B，Emoji 4B	    E4 BD A0
    UTF-16	    可变长度（2 或 4 字节）	    BMP 字符 2B，Emoji 4B	        4F60
    UTF-32	    固定长度（4 字节）	        所有字符 4B	                    00004F60
    */

    // 1️⃣ 普通 ASCII 字符串（UTF-8 兼容）
    cout << "=== 1️⃣ 普通 char 字符串 ===" << endl;
    const char* ascii = "Hello, ASCII!";
    cout << ascii << endl;
    cout << "sizeof(ascii[0]): " << sizeof(ascii[0]) << " 字节" << endl;
    cout << endl;

    // 2️⃣ UTF-8 字符串（多字节编码，每个中文占 3 字节）
    cout << "=== 2️⃣ UTF-8 字符串 ===" << endl;
    const char* utf8_str = u8"你好，世界";  // UTF-8 编码
    cout << utf8_str << endl;
    cout << "UTF-8 字节长度: " << strlen(utf8_str) << endl;
    cout << endl;

    // 3️⃣ 宽字符（Windows 常用 UTF-16，Linux 常用 UTF-32）
    cout << "=== 3️⃣ 宽字符字符串 (wchar_t) ===" << endl;
    const wchar_t* wide_str = L"你好，C++！";
    wcout.imbue(locale(""));  // 启用系统本地化，确保控制台输出中文
    wcout << wide_str << endl;
    cout << "sizeof(wchar_t): " << sizeof(wchar_t) << " 字节" << endl;
    cout << endl;

    // 4️⃣ UTF-16 编码（每个元素 2 字节）
    cout << "=== 4️⃣ UTF-16 字符串 (char16_t) ===" << endl;
    u16string utf16_str = u"你好";
    cout << "UTF-16 长度(字符数): " << utf16_str.size() << endl;
    cout << "UTF-16 每个元素大小: " << sizeof(char16_t) << " 字节" << endl;
    cout << endl;

    // 5️⃣ UTF-32 编码（每个元素 4 字节，一个字符就是一个码点）
    cout << "=== 5️⃣ UTF-32 字符串 (char32_t) ===" << endl;
    u32string utf32_str = U"你好";
    cout << "UTF-32 长度(字符数): " << utf32_str.size() << endl;
    cout << "UTF-32 每个元素大小: " << sizeof(char32_t) << " 字节" << endl;
    cout << endl;

    // 6️⃣ UTF-8 ↔ UTF-16 转换示例（演示）
    cout << "=== 6️⃣ UTF-8 ↔ UTF-16 转换 ===" << endl;
    string utf8_text = u8"Boost C++ 世界";

    // 转换 UTF-8 -> UTF-16
    wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert16;
    u16string utf16_text = convert16.from_bytes(utf8_text);

    cout << "UTF-16 长度: " << utf16_text.size() << endl;

    // 再转换回 UTF-8
    string back_to_utf8 = convert16.to_bytes(utf16_text);
    cout << "回转为 UTF-8: " << back_to_utf8 << endl;

    cout << endl;

    // 7️⃣ Unicode 码点输出
    cout << "=== 7️⃣ Unicode 码点 (UTF-32) ===" << endl;
    for (char32_t ch : utf32_str) {
        cout << "字符: " << (char)ch << " 码点: U+" << hex << (int)ch << dec << endl;
    }

    return 0;
}
