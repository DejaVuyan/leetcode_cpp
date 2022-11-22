#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;  // 要返回的全部组合
        if (digits.empty()) {
            return combinations;
        }
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

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);   // 到了最后一个数字，就将combination推入组合
        } else {
            char digit = digits[index];  // 第一次进入index=0,读取第一个数字
            const string& letters = phoneMap.at(digit);  // 读取数字对应的字符串
            for (const char& letter: letters) {
                combination.push_back(letter);  // 将当前的letter放在combination的后面
                backtrack(combinations, phoneMap, digits, index + 1, combination);  // 再调用，此时digits为2，combination已经放入了第一个字母
                combination.pop_back();  // pop(即清空)当前的combination,为下次做准备
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
