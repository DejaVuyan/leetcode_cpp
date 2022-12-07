#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0,p1=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1){
                swap(nums[p1],nums[i]);
                p1++;
            }
            else if (nums[i]==0)
            {
                swap(nums[p0],nums[i]);
                if (p0<p1) swap(nums[p1],nums[i]);
                p0++;
                p1++;
            }
        }
    }
};



int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    vector<int> nums={2,0,2,1,1,0};
    // 初始化类
    Solution sol;
    int ret = sol;
    cout << "the ret is : " << ret << endl;
    return 0;
}
