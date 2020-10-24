/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-23 14:37:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0205\0205.hpp
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
    bool isIsomorphic(string s, string t) {
		map<char, char> m;
		if(s.size() == 0) return true;		
        for(int i = 0; i < s.size(); ++i) {
			if(m.count(s[i]) == 0) {
				for(auto& r : m) {
					if(r.second == t[i])
						return false;
				}
				m[s[i]] = t[i];				
			}
			else if(m[s[i]] != t[i]) {
				return false;
			}
		}
		return true;
    }
};
