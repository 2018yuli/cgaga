#include <iostream>

void demo() {
    // 1. 定义一个整型变量
    int a = 10;
    
    // 2. 定义一个指向 int 类型的指针
    int* ptr = &a;  // ptr 是指向 a 的指针
    
    // 3. 定义一个指向指针的指针（即二级指针）
    int** ptr2 = &ptr;  // ptr2 是指向 ptr 的指针

    // 4. 打印出值和指针的地址
    std::cout << "a 的值: " << a << std::endl;      // 输出: 10
    std::cout << "ptr 指向的值: " << *ptr << std::endl; // 输出: 10
    std::cout << "ptr2 指向的地址（ptr 的地址）: " << *ptr2 << std::endl; // 输出: ptr 地址
    std::cout << "ptr2 指向的值: " << **ptr2 << std::endl;  // 输出: 10

    // 5. 修改值
    **ptr2 = 20;  // 通过二级指针修改 a 的值

    std::cout << "修改后的 a 的值: " << a << std::endl; // 输出: 20
    std::cout << "ptr 指向的值: " << *ptr << std::endl; // 输出: 20
    std::cout << "ptr2 指向的值: " << **ptr2 << std::endl;  // 输出: 20

    // 6. 通过指向指针的指针修改指针的指向
    int b = 30;
    *ptr2 = &b;  // 修改 ptr2 所指向的指针，让 ptr 指向 b

    std::cout << "通过二级指针修改后，ptr 指向的值: " << *ptr << std::endl; // 输出: 30
    std::cout << "b 的值: " << b << std::endl;   // 输出: 30
}

int main() {
    demo();
    return 0;
}
