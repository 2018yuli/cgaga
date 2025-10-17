#include <iostream>
#include <vector>   // ✅ 必须包含 vector 头文件
using namespace std;

double average(const vector<int>& v)   // ✅ 使用 const 引用，避免复制且支持只读访问
{
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum / v.size();
}

double average2(const vector<int>& v)
{
    if (v.empty()) return 0.0;
    double sum = 0;
    for (int value : v) sum += value;
    return sum / v.size();
}


double average3(const vector<int>& v)
{
    if (v.empty()) return 0.0;
    double sum = 0;
    vector<int>::const_iterator it = v.begin();  // ✅ 使用 const_iterator
    for (; it != v.end(); ++it) {
        sum += *it;
    }
    return sum / v.size();
}

double average2DV2(vector<vector<int>>& vv)
{
    if (vv.empty()) return 0.0;
    double sum = 0;
    unsigned size = 0;
    for (auto& row : vv) {
        for (int value : row) {
            sum += value;
            size++;
        }
    }
    return sum / size;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    double avg = average(v);
    cout << "Average: " << avg << endl;
    cout << "Average2: " << average2(v) << endl;
    cout << "Average3: " << average3(v) << endl;
    vector<vector<int>> vv = {{1, 2}, {3, 4}};
    cout << "Average2D: " << average2DV2(vv) << endl;
    return 0;
}
