#include <iostream>

int main() {
    // 定义一个字符数组
    char arr[] = "Hello, World!";
    
    // 定义一个指针 cp，指向数组的第一个元素
    char *cp = arr;
    
    std::cout << "Original pointer cp points to: " << *cp << std::endl; // 输出 'H'

    // 解释: cp 是一个指针，指向数组的第一个元素 'H'
    // 现在演示两种指针的递增方式: ++cp 和 cp++

    // 1. ++cp 操作
    char *cp2 = ++cp;  // 先将 cp 增加 1，然后将新的 cp 地址赋给 cp2

    std::cout << "After ++cp: cp points to: " << *cp << std::endl; // 输出 'e'
    std::cout << "cp2 points to: " << *cp2 << std::endl; // 输出 'e'，cp 和 cp2 都指向 'e'

    // 2. cp++ 操作
    char *cp3 = cp++;  // 先将 cp 的值赋给 cp3，然后 cp 增加 1

    std::cout << "After cp++: cp points to: " << *cp << std::endl; // 输出 'l'
    std::cout << "cp3 points to: " << *cp3 << std::endl; // 输出 'e'，cp3 指向 'e'

    // 最后输出整个字符数组，以查看指针的移动
    std::cout << "Original array: " << arr << std::endl;

    return 0;
}
