#include <iostream>
#include <vector>
using namespace std;

double average(const vector<int>& v)
{
    if (v.empty()) return 0.0;
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
    vector<int>::const_iterator it = v.begin();
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
    return size ? sum / size : 0.0;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << "Average: " << average(v) << endl;
    cout << "Average2: " << average2(v) << endl;
    cout << "Average3: " << average3(v) << endl;

    vector<vector<int>> vv = {{1, 2}, {3, 4}};
    cout << "Average2D: " << average2DV2(vv) << endl;

    // ✅ 修正：创建 8x12 的二维向量，所有值为 3
    vector<vector<int>> vv1(8, vector<int>(12, 3));
    cout << "Average2D vv1: " << average2DV2(vv1) << endl;

    return 0;
}
