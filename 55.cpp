#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=nums.size();   // 需要走的步数
        int max_step=0;   // 当前最大的步数
        // 遍历找目标索引的步数范围内最大的进行跳转
        int begin_index=0;
        // int begin_step=nums[0];
        while (1)
        {
            // 遍历range
            for (int i=begin_index;i<begin_index+nums[begin_index];i++){
                max_step=max(max_step,nums[i]);   // 找出最大的步数,记录索引
                // 不好记录索引
                // 判断是否满足条件
                if((begin_index+max_step)>l) return true;
            }
            // 更新起点,跳过去
            begin_index=max_step+max_index;
            max_step=0;
            // 当跳不动了的时候还没到达终点就返回true
            // 不太好判断是否满足退出条件
        }
        
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
