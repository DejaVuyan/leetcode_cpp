#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 从右到左找第一个升序
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        // 找从[i+1,end)的第一个大于nums[i]的值
        if (i >= 0) {   
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            // 找到了跳出来
            swap(nums[i], nums[j]);  // 交换
        }
        reverse(nums.begin() + i + 1, nums.end());  // 将从i+1到end重新排列，如果i=0就重排全部数组，左闭右开
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
