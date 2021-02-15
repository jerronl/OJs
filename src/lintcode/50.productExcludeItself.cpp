/*
 * 50.productExcludeItself.cpp
 *
 *  Created on: Feb 14, 2021
 *      https://www.lintcode.com/problem/50
 *      Given an array of integers, B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.
 */
#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int n=nums.size(),i=0;
    	vector<long long> res(n--);
    	for(long long prod=1;i<n;){
    		prod*=nums[i++];
    		res[i]=prod;
    	}
    	for(long long prod=res[0]=1;--i>=0;)
    		res[i]*=(prod*=nums[i+1]);
    	return res;
    }
};

int main() {
	Solution s;
	vector<pair<vector<int>,vector<long long>>> tests ={
			{{11,22,33,44,55,66,77,88,99},{77786550737280,38893275368640,25928850245760,19446637684320,15557310147456,12964425122880,11112364391040,9723318842160,8642950081920}},
			{{1,2,3},{6,3,2}},
			{{2,4,6},{24,12,8}}
	};
	for (auto test : tests) {
		if (s.productExcludeItself(test.first)!= test.second) {
			cout << "FAILED!" << test <<s.productExcludeItself(test.first) ;
			return 0;
		}
	}
	cout << "SUCCEED!";
	return 0;
}







