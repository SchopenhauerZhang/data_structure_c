//
//  main.cpp
//  two_pointers
//
//  Created by schopenhauerzhang on 2020/5/15.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>

using namespace std;

// 快慢指针
struct point{
    int val;
    point * next;
};

point * creatp(int l){
    int n = 0;
    struct point * p = (point  *)malloc(sizeof(point));
    
    struct point * res ;
    res = (point  *)malloc(sizeof(point));
    p->val = 9;
    res =p;
    while(l > 0){
        struct point * pc = (point  *)malloc(sizeof(point));
        pc->val = l;
        p->next = pc;
        p = p->next;
        l--;
    }
    p->next=res;
    return res;
}

// _exists_circle
bool _exists_circle(point * p){
    bool is_exists = false;
    
    point * slow;
    point * fast;
    slow = p;
    fast = p->next;
    
    while(slow==fast){
        if(fast== NULL){
            break;
        }
        fast=fast->next;
    }
    
    
    if(fast == slow){
        is_exists = true;
    }
    
    return is_exists;
}

// _exists_circle
bool __exists_circle(struct point *head){
    bool is_circle = false;
    struct point * fast;
    struct point * slow;
    fast =slow =head;
    fast=fast->next->next;
    
    //  相同速度跑圈,不是环就不会相遇
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
        if(slow!= NULL && fast != NULL ){
            is_circle = true;
            break;
        }
    }
   
    return is_circle;
}

// 寻找链表中间点
struct point * _find_minddle_porint(struct point *p){
    struct point *slow;
    struct point * fast;
    fast= slow =p;
    while(fast != NULL && fast->next != NULL){
        fast= fast->next->next;
        slow= slow->next;
    }
    // 注意链表的奇、偶数
    return slow;
}

// 寻找链表的倒数第k个元素
struct point * _find_k_last_pointer(struct point * p,int k){
    struct point * fast;
    struct point * slow;
    slow = fast = p;

    while(k-- > 0){
        fast=fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    
    return slow;
}


// 左右指针

// 二分查找
int binrysearch(int nums[], int  target,int length){
    int mid=0;
    int left ,right;
    right = length  -1;
    left = 0;
    
    while(left < right){
        mid = (left+right)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid]>target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    
    return mid;
}

// 升序数组中找出2个index1和index2之和为target（inde2>index1>0）;index1和index2不能重复
int * get_index1_index2(int nums[],int length, int target){
    int left = 0;
    int right = length-1;
    int r[2];
    
    while(left < right){
        if(nums[left]+nums[right] == target){
            r[0]= left+1 ;
            r[1] = right+1;
            break;
        }else if(nums[left] + nums[right]<target){
            left ++;
        }else{
            right ++;
        }
    }
    
    return r;
}

// 数组反转
int * reverse_array(int nums[]){
    int left = 0;
    int right = 0;
    
    while(left < right){
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left ++;
        right --;
    }
    
    return nums;
}

// 计算从起点 start 到终点 target 的最近距离
//int BFS(Node start, Node target) {
//    Queue<Node> q; // 核心数据结构
//    Set<Node> visited; // 避免走回头路
//
//    q.offer(start); // 将起点加入队列
//    visited.add(start);
//    int step = 0; // 记录扩散的步数
//
//    while (q not empty) {
//        int sz = q.size();
//        /* 将当前队列中的所有节点向四周扩散 */
//        for (int i = 0; i < sz; i++) {
//            // 从队列删除元素
//            Node cur = q.poll();
//            /* 划重点：这里判断是否到达终点 */
//            if (cur is target)
//                return step;
//            /* 将 cur 的相邻节点加入队列 */
//            for (Node x : cur.adj())
//                if (x not in visited) {
//                    q.offer(x);// 添加元素
//                    visited.add(x);
//                }
//        }
//        /* 划重点：更新步数在这里 */
//        step++;
//    }
//}

// 找出二叉树的最小深度
//int BFS_min_deep(Node n){
//    Queue<Node> q;
//    Set<Node> s;
//    int step = 0;
//
//    q.push(n);
//    s.insert(n);
//
//    while(!q.empty()){
//        int sz = q.size();
//        for (int size = 0;size < sz ;size++){
//            Node p = q.pop();
//            if(p.left == NULL && p.right == NULL){
//                return step;
//            }
//            if(p.left != NULL){
//                p.insert(p.left)
//            }
//            if(p.right != NULL){
//                p.insert(p.right)
//            }
//        }
//        step ++;
//    }
//
//    return step;
//}

// 双向bfs：从 "0000" 开始，转一次，可以穷举出 "1000", "9000", "0100", "0900"... 共 8 种密码。
// 然后，再以这 8 种密码作为基础，对每个密码再转一下，穷举出所有可能.如初出现不能出现的组合就跳过.找出target的最小旋转次数
string plusone(string s, int sign){
    if(s[sign] != '9'){
        s[sign] += 1;
    }else{
        s[sign] = '0';
    }
    
    return  string(s);
}

string downone(string s, int sign){
    if(s[sign] != '0'){
        s[sign] -= 1;
    }else{
        s[sign] = '9';
    }
    
    return  string(s);
}

int openLock(string deadends[], int length, string target){
    std::set<string> dead;
    std::set<string> q2;
    std::set<string> q1;
    std::set<string> vi;
    
    int step =0;
    
    for(int i = 0 ;i<length;i++) dead.insert(deadends[i]);
    q1.insert("0000");
    q2.insert(target);
    
    while(q1.size() != 0  && q2.size() != 0){
        std::set<string> temp;
        std::set<string> tmp;
        
        // 选择从小的集合开始扩散，提高效率
        if(q1.size() > q2.size()){
            tmp = q1;
            q1 = q2;
            q2 = tmp;
        }
        
        for (string s : q1) {
            if(dead.count(s)){
                continue;
            }
            if(q2.count(s)){
                return step;
            }
            
            for(int i =0;i<4;i++){
                string res= plusone(s, i);
                if(!vi.count(res)){
                    temp.insert(res);
                }
                
                string ress= downone(s, i);
                if(!vi.count(ress)){
                    temp.insert(ress);
                }
            }
            
            if(!vi.count(s)){
                vi.insert(s);
            }
            
        }
        
        q1 = q2;
        q2 = temp;
        step ++;
    }
    
    return -1;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    point * p = (point  *)malloc(sizeof(point));
    p = creatp(10);
    printf("%d",_exists_circle(p));
    return 0;
}
