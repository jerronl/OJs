/*
 * 1647.minDeletions.cpp
 *
 *  Created on: June 30, 2022
 *      Author: jerron
 *      https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 *     Given an integer array nums of size n, return the minimum number of increment/decreament of an element by 1 required to make all array elements equal.
 */
#include "../utils/utils.h"

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums.size()/2,sum=0;
        for(int i=0;i<m;++i)
            sum+=nums[m]-nums[i];
        for(int i=m+1;i<nums.size();++i)
            sum+=nums[i]-nums[m];
        return sum;
    }
};



int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
        {{1,2,3},2},
        {{-1,-2,-3},2},
        {{1,10,2,9},16},
        {{0,0,0,0,0,0,10},10},
        {{1},0}
    };
    for (auto test : tests) {
        auto tmp=s.minMoves2(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









