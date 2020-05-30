//
//  main.cpp
//  coins
//
//  Created by schopenhauerzhang on 2020/5/11.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// 迭代使用dp table优化凑零钱
int coins(vector<int>& coins, int amonut){
    // 初始化默认值是11
    vector<int> dp(amonut+1, amonut+1);
    dp[0] = 0;
    for(int i =0;i<dp.size();i++){
        for(int coin : coins){
            if(i-coin<0){
                continue;
            }
            dp[i]=min(dp[i],1+dp[i-coin]);
            cout<<i<<dp[i]<<endl;
        }
    }
    
    return (dp[amonut] == amonut+1)?-1:dp[amonut];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> dp(3,3);
    dp[0]=1;
    dp[1]=2;
    dp[2]=5;
    std::cout<<"coins："<<coins(dp,10)<<endl;
    return 0;
}
