#include <iostream>
using namespace std;

int main() {
    cout << "=== 一般指针的定义与用法 ===" << endl;
    int a = 10;
    double b = 3.14;
    char c = 'X';

    // 1. 定义不同类型的指针
    int* pA = &a;
    double* pB = &b;
    char* pC = &c;

    cout << "变量 a 的地址: " << &a << ", 指针 pA 的值(即地址): " << pA << ", *pA = " << *pA << endl;
    cout << "变量 b 的地址: " << &b << ", 指针 pB 的值(即地址): " << pB << ", *pB = " << *pB << endl;
    cout << "变量 c 的地址: " << (void*)&c << ", 指针 pC 的值(即地址): " << (void*)pC << ", *pC = " << *pC << endl;
    cout << "指针大小: " << sizeof(pA) << " 字节 (通常为4或8字节, 取决于系统)" << endl << endl;


    cout << "=== 指针数组的定义与用法 ===" << endl;
    int x = 1, y = 2, z = 3;
    int* ptrArr[3] = { &x, &y, &z };  // 指针数组：数组中每个元素都是指针

    cout << "指针数组内容：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "ptrArr[" << i << "] = " << ptrArr[i]
             << ", *ptrArr[" << i << "] = " << *ptrArr[i] << endl;
    }
    cout << "指针数组占用空间: " << sizeof(ptrArr) << " 字节" << endl << endl;


    cout << "=== 数组指针的定义与用法 ===" << endl;
    int arr[3] = { 10, 20, 30 };
    int (*pArr)[3] = &arr;  // 数组指针：指向整个数组的指针【int* (ptrArr[3]) 通过 (*pArr)[3] 取值； 与 (*pArr)[3] 通过 *ptrArr[3] 取值】

    cout << "数组指针 pArr 的值(即数组首地址): " << pArr << endl;
    cout << "通过数组指针访问元素：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "(*pArr)[" << i << "] = " << (*pArr)[i] << endl;
    }
    cout << "数组指针占用空间: " << sizeof(pArr) << " 字节" << endl << endl;


    cout << "=== 指针数组 vs 数组指针 的区别 ===" << endl;
    cout << "指针数组定义: int* ptrArr[3]  -> 本质是数组，每个元素都是指针" << endl;
    cout << "数组指针定义: int (*pArr)[3]  -> 本质是指针，指向一个数组" << endl;
    cout << "区别在于括号位置不同。" << endl;
    cout << "ptrArr[0] 表示第一个指针的值，而 (*pArr)[0] 表示数组第一个元素。" << endl;

    return 0;
}
