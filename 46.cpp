#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

class Solution {
private:
    int numsSize;
    vector<int> nums;
    vector<int> path;
    vector<vector<int>> restVecVec;

public:
    void dfs(const int deepth, vector<bool> used)
    {
        // 定义一个used去表示每个数字是否用过
        if (numsSize == deepth) {
            restVecVec.emplace_back(path);
            return;
        }

        // 
        for (int i = 0; i < numsSize; i++) {
            if ( used[i] ) {
                continue;   // 每一层的循环都从0开始只是跳过用过的
            }

            path.emplace_back(nums[i]);   // 跟Push_back一个功能
            used[i] = true;
            dfs(deepth + 1, used);
            used[i] = false; // 在这里表明退出了下一层，所以回退状态，把用过的记录抹掉
            path.pop_back();  // 把path中存的数弹出来，不然会重复
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        numsSize = nums.size();
        this->nums = nums;
        vector<bool> used(numsSize, false);  // 创建一个全为0的数组

        dfs(0, used);

        return restVecVec;
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
