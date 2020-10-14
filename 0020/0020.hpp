/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:32:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
 */
#include <map>
#include <stack>
#include <vector>
#include <string>

using namespace std;

//'('��')'��'{'��'}'��'['��']'

class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 != 0)
			return false;

		std::stack<char> recorder;

		for (char c : s) {
			if (!recorder.empty() && (recorder.top() + 1 == c || recorder.top() + 2 == c))
				recorder.pop();
			else
				recorder.push(c);

		}
		return recorder.empty();
	}
};