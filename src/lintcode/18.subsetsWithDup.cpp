/*
 * 18.subsetsWithDup.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/18
 *     Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> results{{}};
        sort(nums.begin(),nums.end());
        int prev=INT_MIN,pos=0,i,j;
        for(auto n:nums){
            for(i=prev==n?pos:0,j=results.size();i<j;++i){
                results.push_back(results[i]);
                results.back().push_back(n);
            }
            prev=n;
            pos=j;
        }
        return results;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,vector<vector<int>>>> tests={
        {{},{{}}},
        {{1},{{},{1}}},
        {{1,1},{{},{1},{1,1}}},
        {{1,2},{{},{1},{2},{1,2}}},
        {{1,2,2},{{},{1},{2},{1,2},{2,2},{1,2,2}}}
    };
    for (auto test : tests) {
        auto tmp=s.subsetsWithDup(test.first);
        if(!asserteqv(tmp,test.second)){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
