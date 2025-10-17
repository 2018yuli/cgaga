#include <iostream>

int fun1_fixed() {
    int* x = new int(3);
    int value = *x;
    delete x;
    x = nullptr;
    return value;
}

int fun2() {
    int x = 3;
    return x;
}

int main() {
    std::cout << "Hello" << std::endl;
    fun1_fixed();
    return 0;
}