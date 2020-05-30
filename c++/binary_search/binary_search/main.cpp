//
//  main.cpp
//  binary_search
//
//  Created by schopenhauerzhang on 2020/5/12.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//

#include <iostream>
using namespace std;

// 二分查找,前提是数据有序
//int binary_find(int[] nums,int target){
//    int left = 0;
//    int right =nums.length -1;
//    while(left <= right){
//        int mid = (left+right)/2;
//        if(nums[mid] == target){
//            return mid;
//        }else if(nums[mid] < target){
//            left = mid+1;
//        }else if(nums[mid] > target){
//            right = mid-1;
//        }
//    }
//    return -1;
//}
// 左侧边界
int left_bound(int nums[], int target,int len) {
    if (len == 0) return -1;
    int left = 0;
    int right = len; // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意，如果mid-1那么就会少算一个,因为是[)
        }
    }
    return left==len?-1:left;
}
// 优化归一算法(左边界)
int left_middle_bound(int nums[], int target,int len) {
    if (len == 0) return -1;
    int left = 0;
    int right = len-1; // 注意

    while (left <= right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid-1; // 注意，如果mid-1那么就会少算一个,因为是[)
        }
    }
    return left>len or right < len?-1:left;
}
// 右侧边界
int right_bound(int nums[], int target,int len) {
    if (len == 0) return -1;
    int left = 0;
    int right = len; // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid+1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意，如果mid-1那么就会少算一个,因为是[)
        }
    }
    
    return nums[left-1]==target?left:-1;
}
// 右侧边界优化
int right_middle_bound(int nums[], int target,int len) {
    if (len == 0) return -1;
    int left = 0;
    int right = len-1;

    while (left <= right) {
        int mid =left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid+1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid-1;
        }
    }
    
    if(right < 0 || nums[right]!=target){
        return -1;
    }
    return right;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a[]={1,2,3,5,5};
    std::cout << right_middle_bound(a,5,5)<<endl;
    return 0;
}
