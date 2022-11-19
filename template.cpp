#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;




int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="pwwkew";
    // 初始化类
    Solution sol;
    int ret = sol.lengthOfLongestSubstring(s);
    cout << "the ret is : " << ret << endl;
    return 0;
}
