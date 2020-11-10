/*
 * @Author: your name
 * @Date: 2020-11-06 14:27:57
 * @LastEditTime: 2020-11-06 14:42:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\208.实现-trie-前缀树.cpp
 */
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

