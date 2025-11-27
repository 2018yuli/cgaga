#include <iostream>
// 智能指针头文件
#include <memory>

// 自定义删除器
void customDelete(int* ptr) {
    std::cout << "Custom delete called\n";
    delete ptr;
}

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor\n";
    }

    ~MyClass() {
        std::cout << "MyClass destructor\n";
    }

    void greet() {
        std::cout << "Hello from MyClass!\n";
    }
};

int main() {
    // 1. 创建和使用 std::unique_ptr
    std::cout << "=== 1. 创建和使用 unique_ptr ===\n";
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
    ptr1->greet();

    // 2. unique_ptr 不能复制
    std::cout << "\n=== 2. unique_ptr 不能复制 ===\n";
    // 编译错误：不能复制 unique_ptr
    // std::unique_ptr<MyClass> ptr2 = ptr1;  // 错误

    // 3. 使用 std::move 转移所有权
    std::cout << "\n=== 3. 使用 std::move 转移所有权 ===\n";
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);  // 所有权转移到 ptr2
    if (!ptr1) {
        std::cout << "ptr1 is now empty (moved)\n";
    }
    ptr2->greet();

    // 4. unique_ptr 管理动态分配的数组
    std::cout << "\n=== 4. unique_ptr 管理动态分配的数组 ===\n";
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    std::cout << "Array contents: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 5. 使用自定义删除器
    std::cout << "\n=== 5. 使用自定义删除器 ===\n";
    std::unique_ptr<int, decltype(&customDelete)> ptr3(new int(10), customDelete);
    
    // 6. 将 unique_ptr 传递给函数
    std::cout << "\n=== 6. 将 unique_ptr 传递给函数 ===\n";
    // 这行代码定义了一个 Lambda 函数，名为 process。它接受一个类型为 std::unique_ptr<int> 的参数，并打印出该指针所指向的整数值。
    auto process = [](std::unique_ptr<int> p) {
        std::cout << "Processing: " << *p << std::endl;
    };
    std::unique_ptr<int> ptr4 = std::make_unique<int>(100);
    process(std::move(ptr4));  // 使用 std::move 转移所有权
    if (!ptr4) {
        std::cout << "ptr4 is now empty after move\n";
    }

    // 7. 使用 unique_ptr 和 std::make_unique 创建对象
    std::cout << "\n=== 7. 使用 std::make_unique 创建对象 ===\n";
    auto ptr5 = std::make_unique<MyClass>();
    ptr5->greet();

    // 8. unique_ptr 不允许拷贝，但可以传递所有权
    std::cout << "\n=== 8. unique_ptr 不允许拷贝，但可以传递所有权 ===\n";
    std::unique_ptr<MyClass> ptr6 = std::make_unique<MyClass>();
    std::unique_ptr<MyClass> ptr7 = std::move(ptr6);  // 转移所有权
    if (!ptr6) {
        std::cout << "ptr6 is now empty (after move)\n";
    }

    // 9. unique_ptr 与自定义类结合使用
    std::cout << "\n=== 9. unique_ptr 与自定义类结合使用 ===\n";
    {
        std::unique_ptr<MyClass> ptr8 = std::make_unique<MyClass>();
        ptr8->greet();
    }  // ptr8 超出作用域时自动调用 MyClass 的析构函数

    // 10. 通过传递 unique_ptr 所有权避免内存泄漏
    std::cout << "\n=== 10. 通过传递 unique_ptr 所有权避免内存泄漏 ===\n";
    auto ptr9 = std::make_unique<int>(42);
    std::cout << "Before transfer: " << *ptr9 << std::endl;
    std::unique_ptr<int> ptr10 = std::move(ptr9);  // 所有权转移
    if (!ptr9) {
        std::cout << "ptr9 is now empty after transfer\n";
    }
    std::cout << "After transfer: " << *ptr10 << std::endl;

    return 0;
}
