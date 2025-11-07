#include <iostream>
#include <string>
using namespace std;

/*
 * 一、引用的定义和本质
 * -----------------------------------
 * 1. 引用（reference）是C++中一种特殊的“受限制的指针”。
 * 2. 它在语法上更安全，也更易用。
 * 3. 引用一旦绑定，就永远指向初始化的对象，无法再更改。
 */

void basic_reference_demo() {
    cout << "=== 基础引用示例 ===" << endl;

    /*
    内存地址    内容      名称
    0x1000      10        a
    0x1000      10        ref   ← 注意！ref 与 a 指向同一块内存
    //
    // ref 并不是重新开辟一个存储空间；
    // 它只是告诉编译器：“ref 就代表 a”。
    //
    */
    int a = 10;
    //
    // 编译器内部大致相当于：
    // int *const ref = &a;
    // 但是不会开辟新的内存空间
    //
    int &ref = a; // ref 是 a 的引用，也就是 a 的别名

    cout << "a = " << a << ", ref = " << ref << endl;

    ref = 20; // 修改 ref 实际上就是修改 a
    cout << "修改 ref 后，a = " << a << ", ref = " << ref << endl;

    // 引用的地址与被引用变量的地址相同
    cout << "a 的地址：" << &a << endl;
    cout << "ref 的地址：" << &ref << endl;

    // 注意：引用必须在定义时初始化，且不能为 null。
}

/*
 * 二、引用在函数参数传递中的应用
 * -----------------------------------
 * 引用可以避免对象复制，提高性能，
 * 并且允许函数直接修改调用者的变量。
 */

// 传值方式：形参是实参的副本，函数内修改不影响外部
void increment_by_value(int x) {
    x += 1;
}

// 传引用方式：形参是实参的别名，修改直接影响外部
void increment_by_reference(int &x) {
    x += 1;
}

// 传 const 引用：适用于不需要修改参数的大对象
void print_person_info(const string &name, const int &age) {
    cout << "姓名：" << name << "，年龄：" << age << endl;
}

void function_reference_demo() {
    cout << "\n=== 函数参数传递示例 ===" << endl;

    int num = 5;
    increment_by_value(num);
    cout << "传值后 num = " << num << endl;

    increment_by_reference(num);
    cout << "传引用后 num = " << num << endl;

    string name = "张三";
    int age = 28;
    print_person_info(name, age);  // 传 const 引用
}

/*
 * 三、引用与指针的区别
 * -----------------------------------
 * 1. 指针可以为空，引用不能；
 * 2. 指针可以重新指向别的变量，引用不行；
 * 3. 使用引用更安全，更像“变量本身”。
 */

void pointer_vs_reference_demo() {
    cout << "\n=== 引用与指针对比 ===" << endl;

    int a = 100;
    int b = 200;

    int *p = &a; // p 是指针
    int &r = a;  // r 是引用

    cout << "指针 p 指向的值：" << *p << endl;
    cout << "引用 r 的值：" << r << endl;

    // 修改指针的指向
    p = &b;
    cout << "p 改为指向 b 后，*p = " << *p << endl;

    // 引用不能重新绑定到另一个变量
    // r = b;  // 注意：这是修改 a 的值为 b，而不是让 r 指向 b
    cout << "r = b 其实修改了 a，现在 a = " << a << endl;
}

/*
 * 四、引用的实践经验
 * -----------------------------------
 * - 基础类型参数建议传值（int, double...）
 * - 对象类型建议传 const 引用，避免复制开销
 * - 当函数需要修改调用者的变量时，用非 const 引用
 */

class Person {
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};

// 按值传递：复制整个对象（开销大）
void showPersonByValue(Person p) {
    cout << "[值传递] " << p.name << "，" << p.age << endl;
}

// 按 const 引用传递：不复制，不可修改
void showPersonByConstRef(const Person &p) {
    cout << "[const 引用] " << p.name << "，" << p.age << endl;
}

// 按引用传递：可以直接修改原对象
void increaseAge(Person &p) {
    p.age += 1;
}

void practice_experience_demo() {
    cout << "\n=== 实践经验示例 ===" << endl;

    Person p("李四", 20);

    showPersonByValue(p);
    showPersonByConstRef(p);

    increaseAge(p);
    cout << "修改后年龄：" << p.age << endl;
}

/*
 * 主函数：依次调用上面各部分
 */
int main() {
    basic_reference_demo();
    function_reference_demo();
    pointer_vs_reference_demo();
    practice_experience_demo();
    return 0;
}
