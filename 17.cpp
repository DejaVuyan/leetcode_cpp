#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;  // 要返回的全部组合
        // 边界条件，如果给的数字为空则返回空
        if (digits.empty()) {
            return combinations;
        }
        // 哈希表，分别声明key和v的类型，用大括号定义每一对组合
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

// string &combination中说明这个形参是以前实参的引用，他们共用一块内存，形参改变了，跳出函数后实参的值也变了
// string combination，形参和实参是两块空间，两个独立变量

    void backtrack(vector<string>& combinations,unordered_map<char, string>& phoneMap,string& digits, int index,string& combination){
        if (index==digits.length()){    
            combinations.push_back(combination);
            // combination.pop_back();  // 不能写在这里，会导致ade,adf多留了个a
        }
        else{
            // 每一层的数字,每一个index表示取第几个数字
            // int digit=digits[index];
            char digit=digits[index]; 
            string chars=phoneMap.at(digit);    // 数字对应的字符串
            for (int i=0;i<chars.size();i++){
                combination.push_back(chars[i]);  // 把字符串中第i个推入combination
                // 探索下一层的组合
                backtrack(combinations, phoneMap, digits, index+1, combination);
                combination.pop_back();  // 清空
                // 到这里就是触发了回退条件，一种组合已经放到combinations里了
                // 因为combination是共用的，index=0,1,2,...都要用，所以清空他
                
            }
        }

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
