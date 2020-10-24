/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-23 16:44:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0278\0278.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid = (left + right) / 2;
        while(left < right && left != mid && right != mid) {
            if(isBadVersion(mid)) {
                right = mid;
                mid = (left + right) / 2;
            } else {
                left = mid;
                mid = (left + right) / 2;                
            }
        }
		if(isBadVersion(mid)) return mid;
        else return right;
    }
private:
	bool isBadVersion(int n) {
		return n >= 1;
	}
};
