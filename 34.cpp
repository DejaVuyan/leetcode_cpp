#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

// int nums[4] = {1,2,3,4};
//     for (int i:nums){
//     printf("%d \n",ans.size());
// }

int binarySearch_begin(vector<int>& nums,int target){  // 为什么是&？
        //开始位置的二分查找
        // 1.初始化左右边界
        int left=0,right=nums.size()-1;
        // 2.确定退出二分查找条件：左右指针与mid相等
        while(left<right){ // 确保在退出循环的时候left一定等于right
            int mid=(left+right)/2;   // 或者用位移
            // 注意是nums[mid],而不是mid说明区间需要右移，left移动[mid+1,right]
            if(nums[mid]<target) left=mid+1; 
            // 说明 第一个 target肯定不在mid右边，即target位置<=mid，所以区间变成[left,mid]
            else if(nums[mid]==target)  right=mid;
            // nums[mid]>target,说明target肯定不在mid的右边，变为[left,mid-1]
            else right=mid-1;
        }
        // 条件只能保证left==right,不能保证一定找到了target
        if(nums[left]==target) return left;
        else return -1;
    }

int binarySearch_end(vector<int>& nums,int target){  // 为什么是&？
    //结束位置的二分查找
    // 1.初始化左右边界
    int left=0,right=nums.size()-1;
    // 2.确定退出二分查找条件：左右指针与mid相等
    while(left<right){ // 确保在退出循环的时候left一定等于right
        int mid=(left+right+1)/2;   // 或者用位移
        // printf("%d\n",mid);
        // printf("%d\n",left);
        // printf("%d\n",right);
        // 注意是nums[mid],而不是mid说明区间需要右移，left移动[mid+1,right]
        if(nums[mid]<target) left=mid+1; 
        // 说明 最后 target肯定不在mid右边，即target位置>=mid，所以区间变成[mid,right]
        else if(nums[mid]==target)  left=mid;
        // nums[mid]>target,说明target肯定不在mid的右边，变为[left,mid-1]
        else right=mid-1;
    }
    // 条件只能保证left==right,不能保证一定找到了target
    return right;
    // 不需要，因为找开始位置的时候验证过了，else return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size()==0) return vector<int> {-1,-1};  //不要写[-1,-1]因为要求了格式;
    int begin_position = binarySearch_begin(nums,target);
    if (begin_position==-1) return vector<int> {-1,-1};
    int end_position = binarySearch_end(nums,target);
    return vector<int> {begin_position,end_position};
}

int main(){
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ret;
    ret = searchRange(nums,target);
    return 0;
}
