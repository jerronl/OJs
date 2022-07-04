/*
 * 1647.minDeletions.cpp
 *
 *  Created on: June 30, 2022
 *      Author: jerron
 *      https://leetcode.com/problems/wiggle-subsequence/
 *     Given an integer array nums of size n, return the minimum number of increment/decreament of an element by 1 required to make all array elements equal.
 */
#include "../utils/utils.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size(),i,up=1,dn=1;
        for(i=1;i<n;++i)
            if(nums[i]>nums[i-1])
                up=dn+1;
            else if(nums[i]<nums[i-1])
                dn=up+1;
        return max(up,dn);
    }
};



int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
        {{1, 7, 4, 9, 2, 5},6},
        {{1,17,5,10,13,15,10,5,16,8},7},
        {{1,2,3,4,5,6,7,8,9},2},
        {{1},1},
        {{1,1,1,1,1},1}
        // {{},0}
    };
    for (auto test : tests) {
        auto tmp=s.wiggleMaxLength(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









