#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {  // 这个是什么？
            if (i == 0) {   // 在i=0的时候，前0个字符没有字符，肯定匹配不上
                return false;
            }
            if (p[j - 1] == '.') {  // 如果是.直接返回true，注意这里的i,j是第i个数，比较的时候-1表示索引
                return true;
            }
            return s[i - 1] == p[j - 1];  // 判断是否相等
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));   // 前m,前n个，所以要多一个
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];  // 先看是不是与f[i][j-2]相等，即 ab 与abc*这种情况
                     // 如果f[i][j-2]，没有值，不在对角线上,比如f[4][4]去查f[4][2]肯定为0，那么就判断下下面是否匹配
                    if (matches(i, j - 1)) {  
                        f[i][j] |= f[i - 1][j];  // abc 与abc* f[3][4]=f[2][4]=f[2][2]=true 
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];   // 如果match f[1][1]就等于f[0][0]的状态，true
                    }
                    // 所有条件都不满足，去判断下一个状态
                    // 比如初始判断f[0][1],一般情况下是不匹配的，直接进入下一个状态，不在对角线上的都保持初始值0
                }
            }
        }
        return f[m][n];
    }
};


int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="abcd";
    string p="abcd*";
    // 初始化类
    Solution sol;
    int ret = sol.isMatch(s,p);
    cout << "the ret is : " << ret << endl;
    return 0;
}
