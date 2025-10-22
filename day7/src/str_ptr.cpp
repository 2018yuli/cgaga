#include <iostream>
using namespace std;

int main() {
    cout << "===============================" << endl;
    cout << " 🚀  C++ 字符串指针演示 DEMO" << endl;
    cout << "===============================" << endl;

    // 定义一个字符串常量
    /*
    ┌──────────────┐
    │ "Hello\0"    │   ← 这是字符串常量区（不可修改）
    └──────────────┘
        ↑
        │
    str ─┘  （char* 指向首字符 'H'）
    */
    const char* str = "Hello, Pointer!";
    /*
    类比 Rust 中的 let s: &'static str = "Hello";
    ┌──────────────┐
    │ "Hello"      │ ← 静态区数据
    └──────────────┘
    ↑      ↑
    │      │
    │    长度(5)
    └── 指针(&str)
    Rust 不依赖 '\0' 结束，而 C++ 的字符串必须有结尾符号 '\0'。
    */

    cout << "\n[1] 定义字符串指针：" << endl;
    cout << "--------------------------------" << endl;
    cout << "const char* str = \"Hello, Pointer!\";" << endl;
    cout << "str 是一个指针，指向字符串常量的首地址。" << endl;

    /*
    << 操作符针对 char* 做了特殊处理，它会从指针指向的地址开始读取字符
    */
    cout << "\n[2] 打印字符串内容：" << endl;
    cout << "--------------------------------" << endl;
    cout << "字符串内容为：" << str << endl;

    cout << "\n[3] 打印每个字符和地址：" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << "字符 [" << i << "] = '" << str[i] << "'"
             << "   地址 = " << static_cast<const void*>(&str[i]) << endl;
    }

    /*
    这行定义了一个指针 p，让它指向字符串的第一个字符。
        p = 0x100
        *p = 'H'
    */
    cout << "\n[4] 用指针遍历字符串：" << endl;
    cout << "--------------------------------" << endl;
    const char* p = str;
    while (*p != '\0') {
        cout << "当前指针指向字符: '" << *p << "'"
             << "   地址 = " << static_cast<const void*>(p) << endl;
        p++; // 指针向后移动一个字符
    }

    cout << "\n===============================" << endl;
    cout << " ✅ 演示结束：指针移动 = 字符遍历" << endl;
    cout << "===============================" << endl;

    /*
    内存地址   内容
    0x1000     H
    0x1001     e
    0x1002     l
    0x1003     l
    0x1004     o
    ...        ...
    0x100F     ! 
    0x1010     '\0' (字符串结束标志)

    ---

    第一个指针
    "Hello, Pointer!"  ≈  一个 const char[16] 常量
    它在内存中从某个地址开始，比如 0x1000
    str = 0x1000

    "Hello, Pointer!" 会自动退化（decay）为 const char*
    const char* str = &("Hello, Pointer!"[0]);

    所以：
    const char* str = "Hello, Pointer!"; // 等价于 const char str[] = {"Hello, Pointer!"}; 然后 char* str = &str[0];
    *str -> 'H'
    *(str+1) -> 'e'
    ...
    *(str+14) -> '!'

    ---

    再定义一个指针
    const char* p = str;        // 把 str 中存储的值（也就是 0x1000）复制给 p
    const char** p2 = &str;     // 二级指针，指向 str 的地址
    
    
    const char* p = str;

    *p -> 'H'
    *(p+1) -> 'e'
    ...
    *(p+14) -> '!'

    --- 

    内存区域
    char strHelloWorld[11] = { "helloworld" };   // ✅ 数组初始化
    char strHelloWorld2[] = "helloworld";        // ✅ 推断长度的数组初始化
    char* pStrHelloWorld  = "helloworld";        // ✅ 指针指向字符串常量

        名称	      类型	      存储位置	                        是否可修改	    是否独立拷贝字符串	                内存布局特点
    strHelloWorld	char[11]	栈（stack）	                  ✅ 可以修改内容	    ✅ 拷贝了一份	            局部变量，每次函数调用新建
    strHelloWorld2	char[11]	栈（stack）	                  ✅ 可以修改内容	    ✅ 拷贝了一份	            与上相同，只是省略了长度
    pStrHelloWorld	char*	    栈（指针变量） + 只读常量区	    ❌ 不能修改内容	    ❌ 没有拷贝，直接指向常量区	    指针本身在栈上，但字符串内容在只读区
    */

    --- 

    /*
    char strHelloWorld[11] = { "helloworld" };  // 相当于 rust 中的 let v = b"hello".to_vec();  // 创建 Vec<u8>，这里的 strHelloWorld 是不允许修改的
    char* pStrHelloWorld  = "helloworld";       // 相当于 rust 中的 let mut s = "hello";  // 创建 &str, pStrHelloWorld 是允许修改的，但指向的是只读内存区域
    */
    
    return 0;
}
