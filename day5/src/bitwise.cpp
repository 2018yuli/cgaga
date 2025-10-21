#include <iostream>
#include <bitset>
#include <string>

// 定义权限常量（每一位代表一个权限位）
constexpr unsigned int READ    = 1 << 0;  // 0001
constexpr unsigned int WRITE   = 1 << 1;  // 0010
constexpr unsigned int EXECUTE = 1 << 2;  // 0100
constexpr unsigned int DELETE_ = 1 << 3;  // 1000

// 打印权限二进制状态
void printPerm(const std::string& name, unsigned int perm) {
    std::cout << name << " 权限值: " << perm
              << " (二进制: " << std::bitset<4>(perm) << ")\n";
}

// 检查是否拥有某个权限
bool hasPermission(unsigned int userPerm, unsigned int targetPerm) {
    return (userPerm & targetPerm) != 0;
}

// 添加权限
void addPermission(unsigned int& userPerm, unsigned int targetPerm) {
    userPerm |= targetPerm;  // 按位或：添加权限
}

// 移除权限
void removePermission(unsigned int& userPerm, unsigned int targetPerm) {
    userPerm &= ~targetPerm; // 按位与 + 取反：移除权限
}

// 切换权限
void togglePermission(unsigned int& userPerm, unsigned int targetPerm) {
    userPerm ^= targetPerm; // 按位异或：翻转权限
}

int main() {
    unsigned int userPerm = 0;  // 初始权限为 0000（无权限）

    std::cout << "===== 初始状态 =====\n";
    printPerm("用户", userPerm);

    std::cout << "\n===== 添加权限 =====\n";
    addPermission(userPerm, READ);
    addPermission(userPerm, WRITE);
    printPerm("添加READ+WRITE后", userPerm);

    std::cout << "\n===== 检查权限 =====\n";
    std::cout << "是否有执行权限(EXECUTE)? " << (hasPermission(userPerm, EXECUTE) ? "是" : "否") << std::endl;
    std::cout << "是否有写权限(WRITE)? " << (hasPermission(userPerm, WRITE) ? "是" : "否") << std::endl;

    std::cout << "\n===== 移除权限 =====\n";
    removePermission(userPerm, READ);
    printPerm("移除READ后", userPerm);

    std::cout << "\n===== 切换权限(异或) =====\n";
    togglePermission(userPerm, EXECUTE);
    printPerm("切换EXECUTE后", userPerm);

    togglePermission(userPerm, WRITE);
    printPerm("切换WRITE后", userPerm);

    return 0;
}
