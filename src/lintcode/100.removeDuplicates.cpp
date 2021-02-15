/*
 * 100.removeDuplicates.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/100
 *      Given a sorted array, 'remove' the duplicates in place such that each element appear only once and return the 'new' length.
 */
#include "../utils/utils.h"

class Solution {
public:
	/*
	 * @param nums: An ineger array
	 * @return: An integer
	 */
	int removeDuplicates(vector<int> &nums) {
		size_t i = 0, j = 1, n = nums.size();
		for (; j < n; ++j)
			if (nums[j] != nums[i])
				nums[++i] = nums[j];
		return min(n, i + 1);
	}
};
int main() {
	Solution s;
	vector<pair<vector<int>, vector<int>>> tests = { { { }, { } }, {
			{ 1, 1, 2 }, { 1, 2 } } };
	for (auto test : tests) {
		auto tmp = test.first;
		tmp.resize(s.removeDuplicates(tmp));
		if (tmp != test.second) {
			cout << "FAILED!" << test << tmp<<endl;
			return 0;
		}
	}
	cout << "SUCCEED!";
	return 0;
}

