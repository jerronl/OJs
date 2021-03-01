/*
 * 14.binarySearch.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/14
 *     For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            auto m = (l + r) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return l < nums.size() && nums[l] == target ? l : -1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
            {{{1, 2, 3, 3, 4, 5, 10}, 3}, 2},
            {{{1,4,4,5,7,7,8,9,9,10}, 1}, 0},
            {{{1, 2, 3, 3, 4, 5, 10}, 6}, -1},
            {{{}, 0}, -1}
    };
    for (auto test : tests) {
        auto tmp=s.binarySearch(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









