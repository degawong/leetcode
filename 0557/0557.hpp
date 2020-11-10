/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-11-10 17:27:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
 */
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        bool run = true;
        if(s.size() == 0) return s;
        int l = 0;
        int r = 0;
        while(run) {
            while(s[r] != ' ' && r < s.size()) ++r;
            int temp = r;
            if(r == s.size()) run = false;
            while (l < (r - 1)) {
                swap(s[l++], s[r-- - 1]);
            }
            l = r = temp + 1;
        }
        return s;
    }
};
