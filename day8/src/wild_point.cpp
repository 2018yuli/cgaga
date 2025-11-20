#include <iostream>

void demo() {
    // 1. 未初始化指针（Uninitialized Pointer）
    int* ptr1;  // 未初始化的指针
    // std::cout << *ptr1 << std::endl;  // 错误：未初始化的指针解引用，导致未定义行为

    // 2. 空指针（Null Pointer）
    int* ptr2 = nullptr;  // 空指针初始化
    if (ptr2 == nullptr) {
        std::cout << "ptr2 是一个空指针" << std::endl;  // 输出：ptr2 是一个空指针
    }

    // 3. 释放内存后使用的指针（野指针）
    int* ptr3 = new int(10);  // 动态分配内存
    std::cout << "ptr3 指向的值: " << *ptr3 << std::endl;  // 输出：10

    delete ptr3;  // 释放内存
    // std::cout << "释放内存后 ptr3 指向的值: " << *ptr3 << std::endl;  // 错误：野指针，访问已经释放的内存，导致未定义行为
    ptr3 = nullptr;  // 使 ptr3 成为空指针，避免野指针

    // 4. 非法指针（指向未分配内存的指针）
    int* ptr4 = (int*)0xDEADBEEF;  // 非法地址，模拟非法指针
    // std::cout << *ptr4 << std::endl;  // 错误：访问非法内存地址，导致程序崩溃
}

int main() {
    demo();
    return 0;
}
