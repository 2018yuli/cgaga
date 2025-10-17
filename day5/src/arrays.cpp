#include <iostream>
using namespace std;

// 错误示例：sizeof(arr)在函数内退化为指针，无法获取数组长度
double average_fail(int arr[])
{
    double sum = 0;
    // sizeof(arr) 在函数内是指针大小（通常是8字节），不是数组长度
    cout << "sizeof(arr) in function = " << sizeof(arr) << endl;
    // 实际无法正确计算平均值
    return sum;
}

// 正确做法：传入数组长度
double average(int arr[], int length)
{
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return sum / length;
}

// 修正：函数参数应为指针类型 int* arr
double average_point(int* arr, int length)
{
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return sum / length;
}

void array_length_test()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(arr) / sizeof(int);
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }

    cout << "Average (manual): " << sum / (double)length << endl;
    cout << "Average by average_fail(): " << average_fail(arr) << endl;
    cout << "Average by average(length): " << average(arr, length) << endl;
    cout << "Average by average_point(): " << average_point(arr, length) << endl;
}

int main()
{
    array_length_test();
    return 0;
}
