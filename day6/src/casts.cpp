#include <iostream>
using namespace std;

// 基类和派生类
class Base {
public:
    virtual void show() { cout << "Base::show()" << endl; }
    virtual ~Base() = default; // 确保有虚函数表
};

class Derived : public Base {
public:
    void show() override { cout << "Derived::show()" << endl; }
    void derivedFunc() { cout << "Derived specific function" << endl; }
};

int main() {
    cout << "===== static_cast 演示 =====" << endl;
    {
        double d = 3.14;
        int i = static_cast<int>(d);  // 显式类型转换
        cout << "double -> int: " << i << endl;

        Base* b = new Derived();
        // 向下转型（不安全，但编译期允许）
        // Java 也可以向下转型，但运行时检查类型正确性，运行时抛出 ClassCastException
        Derived* d1 = static_cast<Derived*>(b);
        d1->show();
        delete b;
    }

    cout << "\n===== const_cast 演示 =====" << endl;
    {
        const int a = 10;
        const int* p = &a;
        int* p2 = const_cast<int*>(p); // 移除 const 限定
        *p2 = 20; // ⚠️ 未定义行为，仅演示
        cout << "a=" << a << ", *p2=" << *p2 << endl;
    }

    cout << "\n===== dynamic_cast 演示 =====" << endl;
    {
        Base* base1 = new Derived();
        Base* base2 = new Base();

        // 安全的向下转型，运行时检查类型
        Derived* d1 = dynamic_cast<Derived*>(base1);
        if (d1) {
            cout << "base1 -> Derived 成功: ";
            d1->show();
        }

        Derived* d2 = dynamic_cast<Derived*>(base2);
        if (d2 == nullptr)
            cout << "base2 -> Derived 失败，返回 nullptr" << endl;

        delete base1;
        delete base2;
    }

    cout << "\n===== reinterpret_cast 演示 =====" << endl;
    {
        int n = 65;
        char* ch = reinterpret_cast<char*>(&n); // 重新解释内存
        cout << "int 内存 reinterpret_cast 成 char: " << *ch << endl;

        // 指针类型转换（完全不安全）
        Derived* d = new Derived();
        long long addr = reinterpret_cast<long long>(d);
        cout << "指针地址 reinterpret_cast -> long long: " << addr << endl;
        Derived* d2 = reinterpret_cast<Derived*>(addr);
        d2->show();
        delete d;
    }

    return 0;
}
