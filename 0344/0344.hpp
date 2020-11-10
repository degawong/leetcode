
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0) return;
		int l = 0;
		int r = s.size() - 1;
		while(l < r) {
			swap(s[l], s[r]);
		}
    }
};
