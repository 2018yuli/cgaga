#include <iostream>

using namespace std;

void basic_mathematic_operate()
{
    int a = 10;
    cout << "a + 2 = " << (a + 2) << endl;
    cout << "a - 2 = " << (a - 2) << endl;
    cout << "a * 2 = " << (a * 2) << endl;
    cout << "a / 2 = " << (a / 2) << endl;
    cout << "a % 2 = " << (a % 2) << endl;
    cout << "15.0 / a = " << (15.0 / a) << endl;
    cout << "a++ = " << (a++) << endl;
}

void relational_operate()
{
    int a = 10;
    cout << "a == 10 ?" << (a == 10) << endl;
    cout << "a != 10 ?" << (a != 10) << endl;
    cout << "a > 10 ?" << (a > 10) << endl;
    cout << "a < 10 ?" << (a < 10) << endl;
    cout << "a >= 10 ?" << (a >= 10) << endl;
    cout << "a <= 10 ?" << (a <= 10) << endl;
}

void other_operate()
{
    int a = 10;
    // sizeof operator
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;

    // conditional operator
    cout << "a > 5 ? 'yes' : 'no' = " << (a > 5 ? "yes" : "no") << endl;
    
    // , operator
    cout << "a = 10, a + 2 = " << (a = 10, a + 2) << endl;
    
    // . and -> operator
    struct A
    {
        int a;
    };
    // b 是一个 对象，类型是 A
    A b = {10};
    cout << "b.a = " << (b.a) << endl;
    // c 是一个指针，类型是 A*
    // -> 运算符，专门用来“通过指针访问对象的成员”
    // 等价于 (*c).a 即 (*ptr).member
    A *c = &b;
    cout << "c->a = " << (c->a) << endl;
    
    // cast operator
    cout << "int(a) = " << int(a) << endl;
    
    // bitwise operator
    cout << "a & 2 = " << (a & 2) << endl;
    cout << "a | 2 = " << (a | 2) << endl;
    cout << "a ^ 2 = " << (a ^ 2) << endl;
    cout << "~a = " << (~a) << endl;
    cout << "a << 2 = " << (a << 2) << endl;
    cout << "a >> 2 = " << (a >> 2) << endl;
}

int main(int argc, char *argv[])
{
    basic_mathematic_operate();
    
    cout << "---------------------------" << endl;
    relational_operate();
    cout << "---------------------------" << endl;
    other_operate();
    return 0;
}

