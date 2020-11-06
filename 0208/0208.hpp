/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-06 14:43:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0208\0208.hpp
 */

#include <map>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		s.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		return s.count(word) != 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		auto ret = false;
		for(auto& r : s) {
			if(r.size() < prefix.size()) continue;
			if(prefix == r.substr(0, prefix.size())) return true;
		}
		return ret;
    }
private:
	set<string> s;
};
