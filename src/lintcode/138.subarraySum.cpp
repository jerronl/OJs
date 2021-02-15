/*
 * 138.subarraySum.cpp
 *      https://www.lintcode.com/problem/138
 *      Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(const vector<int> &nums) {
        unordered_map<int,int> sums{{0,0}};
        for(int i=0,sum=0;i<(int)nums.size();)
        	if(sums.count(sum+=nums[i]))
        		return{sums[sum],i};
        	else
        		sums[sum]=++i;
        return{};
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,vector<int>>> tests={
        {{-3,1,2,-3,4},{0,2}},
		{{-3, 1, -4, 2, -3, 4},{1,5}}
    };
    for(auto test:tests)
        if (!(s.subarraySum(test.first)==test.second)){
            cout<<"FAILED!"<<test<<s.subarraySum(test.first)<<endl;
            return 0;
        }

    cout<<"SUCCEED!";
    return 0;
 }


