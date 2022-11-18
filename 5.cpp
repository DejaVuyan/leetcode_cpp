#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

string longestPalindrome(string s){
    if (s.size() < 2) return s;
    int begin=0,max_length=1;
    // dp[i][j] 表示 s[i..j] 是否是回文串
    vector<vector<int>> dp(s.size(), vector<int>(s.size())); // 定义一个二维容器，用n个n维的容器填充自己
    // 初始对象线元素
    for(int i=0;i<s.size();i++){
        dp[i][i]=true;
    }
    // 计算下一状态值
    for (int j = 1; j < s.size(); j++)
    {
        for (int i = 0; i < j; i++)
        {       

            // 不能直接下=写这个公式dp[i][j]=
            if (s[i]!=s[j])
            {
                dp[i][j]=false;
            }
            else
            {
                if ((j-i)<3) dp[i][j]=true; //在两头相等的情况下，只要j-i小于3可以直接判定为true
                else dp[i][j]=dp[i+1][j-1]; 
            }
            if (dp[i][j]==true && j-i+1>max_length)
            {
                begin=i;
                max_length=j-i+1;
            }   
        }
        
    }
    return s.substr(begin,max_length);
}

int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="aabbacs";
    string ret = longestPalindrome(s);
    cout << "the ret is : " << ret << endl;
    return 0;
}
