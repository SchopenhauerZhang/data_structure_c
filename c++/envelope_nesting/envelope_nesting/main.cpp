//
//  main.cpp
//  envelope_nesting
//
//  Created by schopenhauerzhang on 2020/5/12.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//

#include <iostream>


int lengthOfLIS(int nums[], int len) {
    int piles = 0;
    int n = len;
    int top[5];
    for (int i = 0; i < n; i++) {
        // 要处理的扑克牌
        int poker = nums[i];
        int left = 0, right = piles;
        // 二分查找插入位置
        while (left < right) {
            int mid = (left + right) / 2;
            if (top[mid] >= poker)
                right = mid;
            else
                left = mid + 1;
        }
        if (left == piles) piles++;
        // 把这张牌放到牌堆顶
        top[left] = poker;
    }
    // 牌堆数就是 LIS 长度
    return piles;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a[]={1,2,6,4,5};
    std::cout<<lengthOfLIS(a,5);
    return 0;
}
