#include <iostream>
#include <memory>  // 引入 shared_ptr 所需的头文件

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor\n";
    }

    ~MyClass() {
        std::cout << "MyClass destructor\n";
    }

    void greet() const {
        std::cout << "Hello from MyClass!\n";
    }
};

int main() {
    std::cout << "=== 1. 创建 shared_ptr ===\n";
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();  // 创建 shared_ptr，管理 MyClass 对象
    ptr1->greet();  // 调用成员函数

    std::cout << "\n=== 2. 共享所有权 ===\n";
    // 创建第二个 shared_ptr，指向相同的对象
    std::shared_ptr<MyClass> ptr2 = ptr1;  // ptr1 和 ptr2 共享相同的对象
    ptr2->greet();

    std::cout << "\n=== 3. 引用计数 ===\n";
    // 检查引用计数
    std::cout << "Use count: " << ptr1.use_count() << std::endl;  // 输出共享对象的引用计数

    std::cout << "\n=== 4. 指针会在最后一个 shared_ptr 被销毁时自动释放 ===\n";
    ptr1.reset();  // 释放 ptr1 的资源
    std::cout << "Use count after reset ptr1: " << ptr2.use_count() << std::endl;

    std::cout << "\n=== 5. shared_ptr 的引用计数归零时，自动删除对象 ===\n";
    ptr2.reset();  // 最后一个 shared_ptr 被销毁时，MyClass 对象也被销毁
    std::cout << "End of main function\n";

    return 0;
}
