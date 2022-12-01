#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 对原数组进行排序
        sort(intervals.begin(),intervals.end());
        // 创建返回容器merge
        vector<vector<int>> merge;
        // int p_merge=0;  // 指向容器中最后一个位置的指针
        merge.push_back(intervals[0]);
        if (intervals.size()==1) return merge;
        // 遍历容器
        for (int i=1;i<intervals.size();i++){
            // 如果左值小于merge右值，必有重复，那么更新右值为两个数组右值的较大值
            if(intervals[i][0]<=merge.back()[1]) merge.back()[1]=max(intervals[i][1],merge.back()[1]);
            else merge.push_back(intervals[i]);
        }
        return merge;
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
