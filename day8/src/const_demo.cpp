#include <iostream>

void demo() {
    // 普通指针：指向整数的指针，可以改变指针的地址以及指向的数据。
    int a = 10;
    int b = 20;
    int* ptr = &a;  // ptr 是一个指向 int 的指针
    std::cout << "普通指针 ptr 指向的值: " << *ptr << std::endl; // 输出 10

    // 修改指针指向的值
    *ptr = 30;
    std::cout << "修改 ptr 指向的值后，a 的值: " << a << std::endl; // 输出 30

    // 修改指针指向的地址
    ptr = &b;
    std::cout << "修改 ptr 指向的新地址后，ptr 指向的值: " << *ptr << std::endl; // 输出 20

    // const pointer：指针本身是常量，指向的地址不能更改，但可以改变指向地址的值
    int* const const_ptr = &a; // int* (const const_ptr)，const_ptr 是一个常量指针，指向的地址不能改变
    std::cout << " (int* const) const_ptr 是一个常量指针，其指向的值: " << *const_ptr << std::endl; // 输出 30

    // 修改指向地址的值
    *const_ptr = 40;
    std::cout << "修改 const_ptr 指向的值后，a 的值: " << a << std::endl; // 输出 40

    // 错误：const_ptr = &b; // 编译错误，不能修改 const_ptr 指向的地址

    // pointer to const：指针指向的内容是常量，不能修改指向的内容，但可以修改指针指向的地址
    const int* ptr_to_const = &a; // (const int*) 而不是 (const const_ptr) ptr_to_const 是一个指向常量的指针
    std::cout << "(const int*) ptr_to_const 是一个指向常量的指针，其指向的值: " << *ptr_to_const << std::endl; // 输出 40

    // 错误：*ptr_to_const = 50; // 编译错误，不能修改指向的值

    // 修改指针指向的地址
    ptr_to_const = &b;
    std::cout << "修改 ptr_to_const 指向的新地址后，ptr_to_const 指向的值: " << *ptr_to_const << std::endl; // 输出 20

    // 常见语法糖示例
    const int* const ptr_to_const_const = &a; // 指向常量的常量指针，既不能修改指向的地址，也不能修改指向的内容
    // 错误：*ptr_to_const_const = 60; //  (const int*) 编译错误，不能修改值
    // 错误：ptr_to_const_const = &b; // (int* const) 编译错误，不能修改地址，类似 java 的 final 关键字
}

int main() {
    demo();
    return 0;
}
