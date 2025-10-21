#include <iostream>
#include <vector>
#include <algorithm>  // sort, find, reverse
#include <numeric>    // accumulate
using namespace std;

// 打印 vector 内容的工具函数
template <typename T>
void print_vector(const vector<T>& v, const string& name = "vector") {
    cout << name << " = [ ";
    for (const auto& x : v) cout << x << " ";
    cout << "] (size=" << v.size() << ", capacity=" << v.capacity() << ")\n";
}

// ==========================================================
// 🧩 基础操作：初始化与遍历
// ==========================================================
void vector_basic() {
    cout << "\n=== vector_basic ===\n";

    vector<int> v1;                     // 空 vector
    vector<int> v2(5);                  // 长度为5，元素为0
    vector<int> v3(5, 42);              // 长度为5，全部初始化为42
    vector<int> v4 = {1, 2, 3, 4, 5};   // 列表初始化

    print_vector(v1, "v1");
    print_vector(v2, "v2");
    print_vector(v3, "v3");
    print_vector(v4, "v4");

    // 遍历
    cout << "v4 遍历: ";
    for (auto it = v4.begin(); it != v4.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// ==========================================================
// 🧩 插入与删除
// ==========================================================
void vector_insert_erase() {
    cout << "\n=== vector_insert_erase ===\n";

    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.push_back(5);
    print_vector(v, "push_back");

    v.insert(v.begin() + 2, 99);   // 在第3个位置插入99
    print_vector(v, "after insert");

    v.erase(v.begin() + 1);        // 删除第二个元素
    print_vector(v, "after erase");

    v.pop_back();                  // 删除最后一个元素
    print_vector(v, "after pop_back");

    v.clear();                     // 清空
    print_vector(v, "after clear");
}

// ==========================================================
// 🧩 查找与排序
// ==========================================================
void vector_search_sort() {
    cout << "\n=== vector_search_sort ===\n";

    vector<int> v = {4, 2, 8, 5, 1};
    print_vector(v, "original");

    // 排序
    sort(v.begin(), v.end());
    print_vector(v, "sorted");

    // 逆序
    reverse(v.begin(), v.end());
    print_vector(v, "reversed");

    // 查找
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end())
        cout << "找到元素 5，索引 = " << distance(v.begin(), it) << endl;

    // 累加
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum = " << sum << endl;
}

// ==========================================================
// 🧩 容量与预分配
// ==========================================================
void vector_capacity() {
    cout << "\n=== vector_capacity ===\n";

    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        cout << "插入 " << i << " 后: size=" << v.size()
             << ", capacity=" << v.capacity() << endl;
    }

    // 预分配容量
    vector<int> v2;
    v2.reserve(10);
    for (int i = 0; i < 10; ++i) v2.push_back(i);
    print_vector(v2, "v2 (reserved)");
}

// ==========================================================
// 🧩 存放自定义结构体
// ==========================================================
struct Person {
    string name;
    int age;
};

void vector_of_struct() {
    cout << "\n=== vector_of_struct ===\n";

    vector<Person> people = {
        {"Alice", 25}, {"Bob", 30}, {"Charlie", 20}
    };

    for (const auto& p : people)
        cout << p.name << " (" << p.age << ")\n";

    // 按年龄排序
    /*
    [捕获列表](参数列表) -> 返回类型 {
        函数体
    }
    [捕获列表]：捕获外部变量（比如 [&] 引用捕获、[=] 值捕获、[] 不捕获）。
    (参数列表)：参数定义。
    -> 返回类型：返回类型（可以省略）。
    {}：函数体。
    */
    /*
    int x = 10;
    auto f = [x]() { return x + 1; };
    // 会生成类似：（不会发生堆分配，通常是栈上分配的普通小对象，几乎总会被内联（inline）优化掉）
    // 所以它的性能和手写函数 bool cmp(int,int) 一样快。
    class __Lambda_1 {
        int x;  // 捕获的外部变量，这个叫做捕获，编译器可以做拷贝省略（RVO / SROA），通常开发者会选择按引用捕获 [&] 或显式传参
    public:
        __Lambda_1(int _x) : x(_x) {}
        int operator()() const { return x + 1; }
    };
    auto f = __Lambda_1(x);
    */
    sort(people.begin(), people.end(),
         [](const Person& a, const Person& b) {
             return a.age < b.age;
         });

    cout << "按年龄排序后:\n";
    for (const auto& p : people)
        cout << p.name << " (" << p.age << ")\n";
}

// ==========================================================
// 🧩 主函数入口
// ==========================================================
int main() {
    vector_basic();
    vector_insert_erase();
    vector_search_sort();
    vector_capacity();
    vector_of_struct();
    return 0;
}
