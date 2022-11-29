#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;
class Solution {
private:
    void backtrack(vector<int>& candidates, int begin, int len, int target, vector<int>& path, vector<vector<int>>& res){
        if(target==0){
            res.push_back(path);  // 推入当前组合到res这个所有组合的容器里
            return;
        }
        for(int i=begin;i<len;i++){   // 遍历当前层所有节点的索引，去除上一层遍历过的节点
            if(target-candidates[i]<0){
                break;
            }
            // 如果target>0说明还要继续往下遍历
            path.push_back(candidates[i]);   // 将节点推入path
            // 往下一层遍历，更新了begin=i,target=target-candidates[i]
            backtrack(candidates,i,len,target-candidates[i],path,res);   
            path.pop_back();  
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int len=candidates.size();
        if(len==0){
            return res;
        }
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        backtrack(candidates,0,len,target,path,res);
        return res;
    }
};




int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    string s="23";
    // 初始化类
    Solution sol;
    auto ret = sol.letterCombinations(s);
    // for(int i=0;i++;i<ret.size()){
    //     cout << "the ret is : " << ret[i] << endl;
    // }
    return 0;
}
