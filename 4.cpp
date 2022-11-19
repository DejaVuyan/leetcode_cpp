#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

// 二分查找
class Solution {
public:
    int binarySearch(vector<int>& nums1, vector<int>& nums2,int k){
        // 函数功能就是查找两个数组中第k小的数
        // 特殊情况，如果有一个数组为空

        // 定义算法中更新后数组的第一个index
        int p_1=0,p_2=0;

        while(true){
            if (nums1.size()==0) return nums2[k-1]; 
            if (nums2.size()==0) return nums1[k-1];
            // 如[1,2],[3,4]找到第3小的，2<3，那么p_1会变为2，超出索引界限了,这时候返回数组2的值就行
            // 这两种特殊情况可以结合一种
            if (p_1==nums1.size()) return nums2[p_2+k-1];
            if (p_2==nums2.size()) return nums1[p_1+k-1];
            // 普通情况，先比较第k/2-1
            // 如果k直接为1了，就是求最小的数，那么直接比较两个数组中的第一个元素
            if (k==1) return min(nums1[p_1],nums2[p_2]);

            // 定义算法和更新各个数组的二分位，也就是要比较的位置，或者说是相对于起始索引的偏移
            int m = nums1.size();
            int n = nums2.size();
            int binary_p1=min(p_1+k/2-1,m-1);  // 防止k超出界限,
            int binary_p2=min(p_2+k/2-1,n-1);


            if (nums1[binary_p1]<=nums2[binary_p2]){
                // 更新k，在更新后的数组里，要找的变成了第k-(binary_p1+1-p_1)小的元素，把新排除的元素数量去掉
                k -= binary_p1 - p_1 + 1;
                // 更新起始索引
                p_1=binary_p1+1; // nums1[binary_p1]与他左边的都被排除了
                // p_2的索引位置就不要变动了               
            }
            else{
                // 同理
                k -= binary_p2 - p_2 + 1;
                p_2=binary_p2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_length=nums1.size()+nums2.size();
        // 奇数
        if (total_length%2==1) return binarySearch(nums1,nums2,(total_length+1)/2); 
        // 偶数就是总长度/2和/2+1小的数的平均值
        else{
            int a=binarySearch(nums1,nums2,total_length/2);
            int b=binarySearch(nums1,nums2,total_length/2+1);
            return (a+b)/2.0;  // 这里表示是double，强制类型转换？
        }
    }
};


int main(){
    // 定义测试用例，或者是用键盘输入的方式定义
    vector<int> nums1 = {0,0,0,0,0},nums2 = {-1,0,0,0,0,0,1};
    // 初始化类
    Solution sol;
    int ret = sol.findMedianSortedArrays(nums1,nums2);
    cout << "the ret is : " << ret << endl;
    return 0;
}
