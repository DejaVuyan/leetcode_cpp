#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

// 寻找两个正序数组的中位数
// 用两个指针，排序，但是不移动元素，遍历到两数组之和的一半，算出中位数
// 寻找两个正序数组的中位数
// 用两个指针，排序，但是不移动元素，遍历到两数组之和的一半，算出中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int med_number=-1;
        int p_1=0,p_2=0;
        int total_length = nums1.size()+nums2.size();
        // 如果是奇数,比如5，中位数就是在索引为2处，也就是5/2
        if (total_length%2==1){
            while ((p_1+p_2)<(total_length/2+1)){
                // 将数比较小的指针加一
                if (nums1[p_1]<=nums2[p_2]) {
                    med_number = nums1[p_1];
                    p_1++;
                }
                else {
                    med_number = nums2[p_2];
                    p_2++;
                }
            }
            return med_number;
        }

        // 如果是偶数，如6，则为索引在2，3处的相加/2，也就是/2和/2减一
        if (total_length%2==0){
            int med_number2=0;
            while ((p_1+p_2)<(total_length/2)){
                // 将数比较小的指针加一
                if (nums1[p_1]<=nums2[p_2]) {
                    med_number = nums1[p_1];
                    p_1++;
                }
                else {
                    med_number = nums2[p_2];
                    p_2++;
                }
            }
            // 将/2位置索引的数字统计出来
            // 这里p_1可能超出界限，超出界限会随机出现一个奇怪数字
            if (p_1<nums1.size()&&p_2>=nums2.size()){
                p_2 = num2.size();
                if (nums1[p_1]<=nums2[p_2]) med_number2=nums1[p_1];  
                else med_number2=nums2[p_2];
            }
            // 加入许多判断
            
            return (med_number+med_number2)/2;
        }
    }
};

int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    vector<int> nums1 = {1,2},nums2 = {3,4};
    // 初始化类
    Solution sol;
    int ret = sol.findMedianSortedArrays(nums1,nums2);
    cout << "the ret is : " << ret << endl;
    return 0;
}
