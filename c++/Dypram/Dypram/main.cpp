//
//  main.cpp
//  Dypram
//
//  Created by schopenhauerzhang on 2020/5/11.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

// 获取全校最大分差
int max_range_score(std::vector<int>& school){
    int result = 0;
    for(int i : school){
        for(int j : school){
            if(j == i){
                continue;
            }
            result = std::max(result,i-j);
        }
    }
    
    return result;
}

void call_max_range_score(){
    std::vector<int> dp(5,5);
    std::cout<<max_range_score(dp)<<std::endl;
}


// 找出二叉树中的最大值
struct btree{
    int val;
    btree * left;
    btree * right;
};

int max_val_btree(btree * bt){
    if(bt == NULL ){
        return -1;
    }
    int left = max_val_btree(bt->left);
    int right = max_val_btree(bt->right);
    
    return max(bt->val,max(left,right));
}



// N皇后问题
//vector<vector<string>> res;
//
///* 输入棋盘边长 n，返回所有合法的放置 */
//vector<vector<string>> solveNQueens(int n) {
//    // '.' 表示空，'Q' 表示皇后，初始化空棋盘。
//    vector<string> board(n, string(n, '.'));
//    backtrack(board, 0);
//    return res;
//}

// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行
//void backtrack(vector<string>& board, int row) {
//    // 触发结束条件
//    if (row == board.size()) {
//        res.push_back(board);
//        return True;
//    }
//
//    int n = board[row].size();
//    for (int col = 0; col < n; col++) {
//        // 排除不合法选择
//        if (!isValid(board, row, col))
//            continue;
//        // 做选择
//        board[row][col] = 'Q';
//        // 进入下一行决策
//        if backtrack(board, row + 1: return True;
//        // 撤销选择
//        board[row][col] = '.';
//    }
//    return False;
//}
//



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";    
    
    return 0;
}
