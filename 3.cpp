#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using std::vector;
using namespace std;

// 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_l = 0;
        int tmp_l = 0;  //记录每一次循环不重复的值
        unordered_set<char> vet;
        // 字符串长度为0或者1的情况?
        // 字符串为空
        if (s.size()==0) return 0;
        if (s.size()==1) return 1;

        for(int p_l=0,p_r=1;p_l<s.size();p_l++,p_r=max(p_l+tmp_l-1,p_l+1)){
            // 开始索引更新后，删除哈希表中开始元素前面的元素,应该清楚所有元素或者索引从
            if (p_l!=0) vet.erase(s[p_l-1]);   
            // 插入左指针的值
            vet.insert(s[p_l]);  // 插入哈希表
            while(!vet.count(s[p_r]) && p_r<s.size()){
                vet.insert(s[p_r]);
                //p_r保持上一次的最大无重复子串索引，这样写有个问题就是p_r不会更新，可能出现p_l>p_r的情况
                p_r++;   
            }
            tmp_l = p_r-p_l;
            max_l=max(max_l,tmp_l);
            // 等于0的话是不用删除的
        }
        return max_l;
    }
};

int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    //测试用例
    // "aab" 2; "pwwkew" 3;"anviaj" 5 
    string s="uqinntq";
    // 初始化类
    Solution sol;
    int ret = sol.lengthOfLongestSubstring(s);
    cout << "the ret is : " << ret << endl;
    return 0;
}