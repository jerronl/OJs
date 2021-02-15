/*
 * 189.firstMissingPositive.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/189
 *      Given an unsorted integer array, find the first missing positive integer.
 */
#include "../utils/utils.h"

class Solution {
public:
	/**
	 * @param A: An array of integers
	 * @return: An integer
	 */
	int firstMissingPositive(vector<int> &A) {
		int n = A.size(), i = 0, j, k;
		for (; i < n; ++i)
			if ((j = A[i] - 1) != i)
				for (A[i] = 0; j >= 0 && j < n && (k = A[j] - 1) != j; j = k)
					A[j] = j + 1;
		for (i = 0; i < n && A[i] > 0; ++i)			;
		return ++i;
	}
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
		{{3,4,-1,1},2},
		{{1,2,0},3}
    };
    for(auto test:tests)
        if (!(s.firstMissingPositive(test.first)==test.second)){
            cout<<"FAILED!"<<test<<s.firstMissingPositive(test.first)<<endl;
            return 0;
        }

    cout<<"SUCCEED!";
    return 0;
 }



