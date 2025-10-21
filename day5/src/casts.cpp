#include <iostream>
#include <cstdint>
#include <iomanip>

int main() {
    int *p = new int(0x11223344);

    std::cout << "sizeof(void*) = " << sizeof(void*) 
              << ", sizeof(int) = " << sizeof(int) << '\n';

    uintptr_t p_as_uintptr = reinterpret_cast<uintptr_t>(p);
    std::cout << "原始指针: 0x" << std::hex << p_as_uintptr << std::dec << '\n';

    // ✅ 正确的做法：先转成 uintptr_t（与指针等宽），再人为截断成 int
    // 在 64 位系统上 void* 是 8 字节，而 int 通常是 4 字节，转换会截断高 32 位地址
    int truncated = static_cast<int>(p_as_uintptr); // 模拟 C 风格截断
    std::cout << "截断后的 int 值 (hex): 0x" << std::hex << (unsigned)truncated << std::dec << '\n';

    int *p_recovered = reinterpret_cast<int*>((uintptr_t)truncated);
    std::cout << "重建的指针: 0x" << std::hex << reinterpret_cast<uintptr_t>(p_recovered) << std::dec << '\n';

    std::cout << "原始值: 0x" << std::hex << *p << std::dec << '\n';
    bool same = (reinterpret_cast<uintptr_t>(p) == reinterpret_cast<uintptr_t>(p_recovered));
    std::cout << "地址相等? " << (same ? "是" : "否（出错）") << '\n';

    delete p;
    return 0;
}
