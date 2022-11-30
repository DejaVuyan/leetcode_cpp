#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=nums.size();   // 需要走的步数
        int max_step=nums[0];   // 当前最大的步数
        for (int i = 0; i < nums.size(); i++)
        {
            // 判断是否可达
            if (i>max_step) return false;
            // 更新最大距离
            max_step=max(max_step,i+nums[i]);
            // 判断是否已经可以到达底部位置
            if (max_step>=nums.size()-1) return true;
        }   
        return false;
    }
};



int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="pwwkew";
    // [2,3,1,1,4]
    // 初始化类
    Solution sol;
    int ret = sol;
    cout << "the ret is : " << ret << endl;
    return 0;
}
