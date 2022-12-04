#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

// 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};


int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    // string s="pwwkew";
    // 初始化类
    Solution sol;
    int ret = sol.uniquePaths(51,9);
    cout << "the ret is : " << ret << endl;
    return 0;
}
