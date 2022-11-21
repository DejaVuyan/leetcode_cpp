#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

// 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 定义一个二维数组作为返回值
        vector<vector<int>> ret;
        // 排序
        sort(nums.begin(),nums.end());  // 将原vector进行排序
        for (int a=0;a<nums.size();a++){
            // if (nums[a]<0 && nums[a]!=nums[a-1]){
            //     // 后续b,c判断
            //     //这样a=0的时候就会报错
            // }
            // // 解决方法，当a>0的时候才判断是不是等于a-1
            if (a>0 && nums[a]==nums[a-1]) continue;
            for (int b=a+1;b<nums.size();b++){
                if (b>a+1 && nums[b]==nums[b-1]) continue;   // 保证b不同
                for (int c=nums.size()-1;c>b;c--){
                    if ((c<nums.size()-1 && nums[c]==nums[c+1]) || (nums[b]+nums[c])>-nums[a] ) continue;
                    if (nums[a]+nums[b]+nums[c]==0){
                        ret.push_back({nums[a],nums[b],nums[c]});  // 推入数组
                        break;
                    }
                }
            }
        }
        return ret;
    }
};


int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="pwwkew";
    // 初始化类
    Solution sol;
    int ret = sol.lengthOfLongestSubstring(s);
    cout << "the ret is : " << ret << endl;
    return 0;
}
