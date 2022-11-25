#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 特殊情况，比如nums没有值，或者找不到
        // nums.length>=1,所以不用考虑没有值的情况
        // 初始的左右边界和mid的index
        int left=0,right=nums.size()-1;
        while(left<=right){   // 这里可能出现等于的情况
            int mid = (left+right)/2;
            // 进行二分查找
            if (nums[mid]==target) return mid;
            // 判断左右区间哪一个有序
            // 如果左边有界，且，就在左边界找
            if (nums[left]<=nums[mid]){   // nums为[0,3]时，left可能与mid重合，这里应该是小于等于
                // 如果有界，查看target是否在[left,mid)之间
                if (nums[left]<=target&&target<nums[mid]){
                    // 缩小查找范围
                    right = mid-1;
                }
                else{  // 就在右区间查找
                    left=mid+1;
                }
            }
            else{  // 右区间有界
                if (nums[right]>=target&&target>nums[mid]){
                    left=mid+1;
                }
                else right = mid-1;
            }
            // 如果左边无界呢，而且又在左边界呢
        }
        return -1;   // 没有搜索到结果
    }
};



int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    vector<int> nums={3,1};
    int target=1;
    // 初始化类
    Solution sol;
    int ret = sol.search(nums,target);
    cout << "the ret is : " << ret << endl;
    return 0;
}
