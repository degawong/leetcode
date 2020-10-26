/*
 * @Author         : degawong
 * @LastEditors    : degawong
 * @Date           : 2020-10-14 19:20:02
 * @LastEditTime   : 2020-10-24 10:51:16
 * @Description    : 
 * 
 * @symbol_custom_string_obkoro1: 
 */
#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		map<char, int> sm;
		map<char, int> tm;
		if(s.size() != t.size()) return false;
		for(int i = 0; i < s.size(); ++i) {
			if(sm.count(s[i]) == 0) sm[s[i]] = 1;
			else sm[s[i]] += 1;
			if(tm.count(t[i]) == 0) tm[t[i]] = 1;
			else tm[t[i]] += 1;			
		}
		if(sm.size() != tm.size()) return false;
		for(auto si = sm.begin(), ti = tm.begin(); si != sm.end(); ++si, ++ti) {
			if(si->first != ti->first || si->second != ti->second) return false;
		}
		return true;
    }
};
