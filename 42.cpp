#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 动态规划找出最大的右值
        vector<int> max_r(height.size());
        int rain_num=0;
        int max_l=height[0];
        int rain=0;
        max_r[height.size()-1]=height[height.size()-1];
        for (int i=height.size()-2;i>=0;i--){
            max_r[i]=max(height[i],max_r[i+1]);
        }
        // 遍历算出每一列的雨水
        for (int i=1;i<height.size()-1;i++){
            // 更新max_l
            max_l=max(max_l,height[i-1]);
            rain = min(max_l,max_r[i])-height[i];
            if(rain>0) rain_num+=rain;   // 这里雨水要大于0才累加，可能会算出负数
        }
        return rain_num;
    }
};



int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    vector<int>qus={0,1,0,2,1,0,1,3,2,1,2,1};
    // 初始化类
    Solution sol;
    int ret = sol.trap(qus);
    cout << "the ret is : " << ret << endl;
    return 0;
}
