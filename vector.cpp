#include <iostream>
#include <vector>
#include <cstring>
#include<unordered_set>

using std::vector;
using namespace std;

// int main(){
//     // vector<int> nums(10);
//     int n=1;
//     printf("%d \n",1<<n);
//     vector<int>ans(1<<n);
//     printf("%d \n",ans.size());
//     return 0;
// }

int main()
{
    string s="pwwkew";
    int max_l = 0;
    int p_r = 1;
    unordered_set<char> vet;
    // 字符串长度为0或者1的情况?
    if (s.size()==1) return 1;

    for(int p_l=0;p_l<s.size();p_l++){
        // 插入左指针的值
        vet.insert(s[p_l]);
        while(!vet.count(s[p_r]) && p_r<s.size()){
            vet.insert(s[p_r]);
            p_r++;
        }
        max_l=max(max_l,(p_r-p_l));
        // 等于0的话是不用删除的
        if (p_l!=0) vet.erase(s[p_l-1]);
    }
}


// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int n = digits.size();
//         while(n && ++digits[--n] == 10) digits[n] = 0;
//         if(digits[0] == 0) digits.insert(begin(digits), 1);
//         return digits;
//     }
// };