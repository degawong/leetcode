/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-11-10 15:41:25
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
    int guessNumber(int n) {
        int l = 1;
		int r = n;
		while(l <= r) {
			int mid = l + (r - l) / 2;
			if(guess(mid) == 0) return mid;
			else if(guess(mid) == 1) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return 0;
    }
private:
	int guess(int n) {
		if(n > 10) return -1;
		if(n < 10) return 1;		
		if(n == 10) return 0;		
	}
};
