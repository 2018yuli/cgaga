#include <iostream>
#include <memory>

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
    // 创建一个 shared_ptr，管理一个 MyClass 对象
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    ptr1->greet();

    std::cout << "\n=== 2. 创建 weak_ptr ===\n";
    // 使用 weak_ptr 观察 shared_ptr 管理的对象（解决 shared_ptr 的，循环引用问题）
    std::weak_ptr<MyClass> weakPtr = ptr1;

    std::cout << "\n=== 3. 使用 weak_ptr 转换为 shared_ptr ===\n";
    // 从 weak_ptr 获取一个临时的 shared_ptr
    if (auto ptr2 = weakPtr.lock()) {  // lock() 尝试获取 shared_ptr
        std::cout << "Successfully locked weak_ptr to shared_ptr.\n";
        ptr2->greet();
    } else {
        std::cout << "Failed to lock weak_ptr.\n";
    }

    // 删除  weak_ptr ptr1，检查的行为
    ptr1.reset();  // 销毁 ptr1 对象，引用计数减少为 0

    std::cout << "\n=== 4. 检查 weak_ptr 是否仍然有效 ===\n";
    if (auto ptr3 = weakPtr.lock()) {  // 再次尝试 lock()
        std::cout << "Successfully locked weak_ptr to shared_ptr.\n";
        ptr3->greet();
    } else {
        std::cout << "Failed to lock weak_ptr. The object has been destroyed.\n";
    }
 
    std::cout << "\n=== 5. weak_ptr 不增加引用计数 ===\n";
    std::cout << "Current use_count of ptr1: " << ptr1.use_count() << std::endl;

    return 0;
}
