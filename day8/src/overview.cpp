#include <iostream>

using namespace std;

int main() {
    int a = 12;
    int* d = &a;
    // 相当于 [d]
    cout << *d << std::endl;
    cout << d << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}