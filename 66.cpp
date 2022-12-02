#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int path_nums=0;
    int move(int m_c,int n_c,int m, int n){
        // m_c,n_c是当前的位置
        // 退出条件
        if(m_c==m-1 && n_c==n-1){
            path_nums++;
            // 退出函数,void不需要返回
            return 1;
        }
        // 在右边界
        if (n_c==n-1){
            move(m_c+1,n_c,m,n);
        }
        // 在左边界
        else if (m_c==m-1){
            move(m_c,n_c+1,m,n);
        }
        
        // 正常移动
        else{
            move(m_c+1,n_c,m,n);
            move(m_c,n_c+1,m,n);
        }
        return 0;
    }
    int uniquePaths(int m, int n) {
        // vector<int> cur_pos={0,0};   // 当前位置
        // vector<int> end_pos={m,n};   // 终点位置
        int tmp;
        tmp=move(0,0,m,n);
        return path_nums;
    }
};

// 由于时间复杂度太高不能通过


int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    // string s="pwwkew";
    // 初始化类
    Solution sol;
    int ret = sol.uniquePaths(51,9);
    cout << "the ret is : " << ret << endl;
    return 0;
}
