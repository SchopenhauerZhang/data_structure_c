//
//  main.cpp
//  sliding_window
//
//  Created by schopenhauerzhang on 2020/5/13.
//  Copyright © 2020 schopenhauerzhang. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

// 要在 S(source) 中找到包含 T(target) 中全部字母的一个子串，且这个子串一定是所有可能子串中最短的.
string minWindow(string s, string t) {
    // like python dict
    std::unordered_map<char, int> need, window;
    // map of t
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT_MAX;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        // c in need ?
        if (need.count(c)) {
            //window is containts target map
            window[c]++;
            if (window[c] == need[c])
                // window containts target count
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (valid == need.size()) {
            // 在这里更新最小覆盖子串
            // log prefix time start pos and length when match expression
            // if next time len < prefix time len,replace it (start pos and len)
            if (right - left < len) {
                // length in window
                start = left;
                len = right - left;
            }
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    // 返回最小覆盖子串
    
    return len == INT_MAX ?
        "" : s.substr(start, len);
}
// redo
string find_max_son_strings_containt_all_characters(string source,string son_strings){
    int max_len = INT_MAX;
    // 限制边界
    if(max_len< son_strings.length() || max_len  < source.length()){
        return "";
    }
    
    std::unordered_map<char, int> be_containt_characters, sliding_window;
    for(char c : son_strings) be_containt_characters[c]++;// 优化，可能存在重复字符
    
    int pos_match = 0;
    int match_len = 0;// default not match
    int min_match_len = max_len;
    int window_left_pos = 0;
    int window_right_pos = 0;
    
    while(window_right_pos < source.length()){
        // end when list all  source character
        
        // insert sliding_window
        sliding_window[source[window_right_pos]] ++;
        
        // match count incrce
        char _ch = source[window_right_pos];
        if(be_containt_characters.count(_ch)){
            // incre match len
            if(be_containt_characters[_ch] == sliding_window[_ch]){
                match_len ++;
            }
        }
        
        // sliding right
        window_right_pos ++;
        
        // reduce window size when all matched
        while(match_len == be_containt_characters.size()){
            // log min_matched position
            if(window_right_pos - window_left_pos < min_match_len){
                pos_match = window_left_pos;
                min_match_len = window_right_pos-window_left_pos;
            }
            _ch = source[window_left_pos];
            // match len,becontainted characters reduce when pop matched characters
            if( be_containt_characters.count(_ch) && be_containt_characters[_ch] == sliding_window[_ch]){
                match_len --;
                sliding_window[_ch]--;
            }
            // left sliding
            window_left_pos ++;
        }
    }
    
    return min_match_len == max_len?"":source.substr(pos_match,min_match_len);
}

// framework
string framwork_slid_window(){
    string source="bcisebsdais";
    string target="biss";
    unordered_map<char, int> window,tagt;
    for(char c : target) tagt[c]++;
    
    int window_right= 0;
    int window_left = 0;
    int match_length = 0;
    int min_match_len = INT_MAX;
    int start_pos = 0;
    
    while(window_right < source.length()){
        
        //TODO 2 update window
        window[source[window_right]] ++;
        if(tagt.count(source[window_right])){
            if(window[source[window_right]] == tagt[source[window_right]]){
                match_length ++;
            }
        }
        
        //TODO 1 slide right window
        window_right ++;
        
        //TODO 3 reduce window
        while(match_length == tagt.size()){
            
            // update res
            if(window_right-window_left < min_match_len){
                min_match_len = window_right - window_left;
                start_pos = window_left;
            }
            
            // update window
            if(tagt.count(source[window_left]) && tagt[source[window_left]] == window[source[window_left]]){
                window[source[window_left]] --;
                match_length --;
            }
            
            // slide left window
            window_left ++;
        }
    }
    
    return min_match_len == INT_MAX ?"":source.substr(start_pos,min_match_len);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout<<framwork_slid_window()<<'\n';
    return 0;
}

