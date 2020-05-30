//
//  main.cpp
//  permutation_in_string
//
//  Created by schopenhauerzhang on 2020/5/13.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/*
 string s = 'adasadbasdasdad';
 string target = 'ab';
 return True(ba)
 
 string s = 'adasadbabasdasdad';
 string target = 'aab';
 return True(aba)
 
 */
bool is_son_strings_exits_in_sources(string sources, string target){
    bool is_exists = false;
    
    if(sources.length()> INT_MAX || sources.length() < target.length()){
        return is_exists;
    }
    
    std::unordered_map<char,int> window,tgt;
    for(char c : target) tgt[c]++;
    
    
    int match_len = 0;
    int window_left = 0;
    int window_right = 0;
    
    while(window_right < sources.length()){
        
        char c = sources[window_right];
        window_right ++;
        window[c] ++;
        
        if(tgt.count(c)){
            if(window[c] == tgt[c]){
                match_len ++;
            }
        }
        
        while(window_right - window_left>=tgt.size()){
            
            c = sources[window_left];
            
            if(match_len == tgt.size()){
                is_exists = true;
                break;
            }
            
            if(tgt.count(c) && window[c] == tgt[c]){
                match_len --;
                window[c] --;
            }
            
            window_left ++;
        }
    }
    
    return is_exists;
}


/**
 这个所谓的字母异位词，不就是排列吗，搞个高端的说法就能糊弄人了吗？相当于，输入一个串 S，一个串 T，找到 S 中所有 T 的排列，返回它们的起始索引。
 */
std::vector<int> get_index_from_string(string source, string target){
    std::vector<int> res;
    unordered_map<char, int> window,t;
    
    int window_right= 0;
    int window_left= 0;
    int match = 0;
    
    for(char c : target) t[c]++;
    
    while(window_right<source.length()){
        char c = source[window_right];
        
        window[c] ++;
        // right sliding
        window_right++ ;
        
        
        // match data
        if(t.count(c) && window[c] == t[c]){
            match ++;
        }
        
        // left sliding
        while(match == t.size()){
            if(window_right-window_left == t.size()){
                res.push_back(window_left);
            }

            c = source[window_left];
            if(t.count(c) && t[c] == window[c]){
                match --;
                window[c] --;
            }
            
            window_left ++;
        }
    }
    
    return res;
}

/**
 找出字符串中最长的无重复子串
 */
string get_longest_unique_substring(string source){
    int max_len = INT_MAX;
    
    if(source.length()> max_len){
        return "";
    }
    
    unordered_map<char, int> window,s;
    for(char c :source) s[c]++;
    
    max_len = 0;
    int window_right =0;
    int window_left = 0;
    int match_len = 0;
    int substr_pos= 0;
    
    while(window_right < source.length()){
        char c = source[window_right];
        window_right++;
        window[c] ++;
        
        if(window[c] == 1){
            match_len ++;
        }
            
        while(match_len < (window_right-window_left)){
            c = source[window_left];
            if(match_len > max_len){
                max_len = match_len;
                substr_pos = window_left;
            }
            
            if(window[c] == 1){
                match_len --;
            }
            
            window[c] --;
            window_left ++;
        }
    }
    
    return  max_len==INT_MAX?"":source.substr(substr_pos,max_len);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout<<get_longest_unique_substring("abcdefabc")<<"\n";
    
    return 0;
}
