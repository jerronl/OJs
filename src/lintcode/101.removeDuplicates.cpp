/*
 * 101.removeDuplicates.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/101
 *      Given a sorted array, remove the duplicates in place such that each element appear at most twice and return the new length.
 */
#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int i = -1, cnt = 0, prev = -1;
        for (auto n : nums) {
            if (n == prev) {
                if (++cnt < 3)
                    prev = nums[++i] = n;
            } else {
                prev = nums[++i] = n;
                cnt = 1;
            }
        }
        return ++i;
    }
};


int main(){
    Solution s;
    vector<pair<vector<int>,vector<int>>> tests={
        {{-8,0,1,2,3},{-8,0,1,2,3}},
        {{1,1,1,2,2,3},{1,1,2,2,3}},
        {{},{}}
    };
    for (auto test : tests) {
        auto tmp = test.first;
        tmp.resize(s.removeDuplicates(tmp));
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }





