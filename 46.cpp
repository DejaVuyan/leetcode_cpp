#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<int>> backtrack(vector<int> nums,vector<int>& combanation){
        vector<vector<int>> combanations;
        for(int i=0;i<nums.size();i++){   
            if (nums.size()>0){
                // 如果还没有遍历到最后一层
                combanation.push_back(nums[i]);
                // 调用下一层的遍历函数
                auto iter=nums.erase(nums.begin()+i);  // erase函数的返回值是被删除元素的后面指针，一个iter
                // 是在原来的数组的基础上删除的
                backtrack(nums,combanation);
            }
            // i=0 遍历完了，nums数组空了,说明一种情况统计完了
            else{
                // 将combanation推入combanations
                combanations.push_back(combanation);
                // 清空combanation
            }
        }
        return combanations;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 处理些特殊情况，或者剪枝
        // 但是此题没有什么特殊情况
        vector<vector<int>> ret;
        vector<int> combanation;
        ret = backtrack(nums,combanation);
        return ret;
    }
};

//定义显示函数
int show(vector<vector<int>> v){
    // 遍历显示
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            cout << "the ret is : " << v[i][j]<< endl;
        }
        cout << ".................." << endl;
    }
}

int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    vector<int> nums={1,2,3};
    // 初始化类
    Solution sol;
    vector<vector<int>> ret = sol.permute(nums);
    show(ret);
    return 0;
}
