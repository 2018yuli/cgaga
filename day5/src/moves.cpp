#include <iostream>
#include <bitset>
#include <iomanip>

// 打印 char 的十进制与二进制表示
void printCharInfo(const std::string& name, int value) {
    std::cout << std::left << std::setw(12) << name
              << " 十进制: " << std::setw(4) << value
              << " 二进制: " << std::bitset<8>(value & 0xFF)
              << std::endl;
}

void demo_shift_difference() {
    // 定义两个字符：一个正数，一个负数
    unsigned char u = 0x63; // 十进制 99，二进制 0110 0011
    signed char s = -0x63;  // 十进制 -99，二进制（补码）1011 1101

    std::cout << "===== 原始值 =====" << std::endl;
    printCharInfo("unsigned u", u);
    printCharInfo("signed s", s);

    std::cout << "\n===== 逻辑右移 (Logical Right Shift) =====" << std::endl;
    unsigned char logical_u = u >> 2; // 高位补 0
    unsigned char logical_s = ((unsigned char)s) >> 2; // 先转无符号，再逻辑右移
    printCharInfo("u >> 2", logical_u);
    printCharInfo("(unsigned)s >> 2", logical_s);

    std::cout << "\n===== 算术右移 (Arithmetic Right Shift) =====" << std::endl;
    signed char arithmetic_s = s >> 2; // 高位补符号位（1）
    printCharInfo("s >> 2", arithmetic_s);

    std::cout << "\n===== 对比总结 =====" << std::endl;
    std::cout << R"(
1. 对 unsigned 类型：
   - 右移是 **逻辑右移**，高位永远补 0。

2. 对 signed 类型（如 char / int）：
   - 右移是 **算术右移**，高位补符号位（负数补 1）。

3. 如果要对有符号数做逻辑右移：
   - 先转换为 unsigned 类型，再右移。
)" << std::endl;
}

int main() {
    demo_shift_difference();
    return 0;
}
