/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-11-10 14:51:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0345\0345.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() == 0) return s;
		int l = 0;
		int r = s.size() - 1;
		while(l < r) {
			if(!is_vowel(s[l])) {++l;continue;}
			if(!is_vowel(s[r])) {--r;continue;}
			swap(s[l++], s[r--]);
		}
		return s;
    }
private:
	bool is_vowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
};
