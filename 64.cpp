#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h=grid.size();
        int w=grid[0].size();
        // 状态数组
        vector<vector<int>> dp(h,vector<int>(w));
        // 初始化一些状态数组，避免特殊条件出错
        dp[0][0]=grid[0][0];
        // 在第一行
        for (int j=1;j<w;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        // 在第一列
        for(int i=1;i<h;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        // 普通
        for(int i=1;i<h;i++){
            for (int j=1;j<w;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[h-1][w-1];
    }
};



int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="pwwkew";
    // 初始化类
    Solution sol;
    int ret = sol;
    cout << "the ret is : " << ret << endl;
    return 0;
}
