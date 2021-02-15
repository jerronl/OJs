/*
 * 56.twoSum.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/56
 *      Given an array of integers, find two numbers such that they add up to a specific target number.
 */
#include "../utils/utils.h"

class Solution {
public:
	/**
	 * @param numbers: An array of Integer
	 * @param target: target = numbers[index1] + numbers[index2]
	 * @return: [index1 + 1, index2 + 1] (index1 < index2)
	 */
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> S;
		for (int i = 0; i < (int) numbers.size(); ++i)
			if (S.count(target - numbers[i]))
				return {S[target-numbers[i]],i};
			else
				S[numbers[i]] = i;
		return {};
	}
};

int main() {
	Solution s;
	vector<pair<pair<vector<int>,int>,vector<int>>> tests ={
			{{{2, 7, 11, 15},9},{0,1}},
			{{{15, 2, 7, 11},9},{1,2}}
	};
	for (auto test : tests) {
		if (s.twoSum(test.first.first, test.first.second)!= test.second) {
			cout << "FAILED!" << test <<s.twoSum(test.first.first, test.first.second) ;
			return 0;
		}
	}
	cout << "SUCCEED!";
	return 0;
}




