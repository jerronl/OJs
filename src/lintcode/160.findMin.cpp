/*
 * 160.findMin.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/159
 *     Suppose a sorted array in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        if (r < 0)
            return -1;
        while (l < r && nums[l] >= nums[r]) {
            auto m = (l + r) / 2;
            if (nums[l] < nums[m])
                l = m + 1;
            else if (nums[l] > nums[m])
                r = m, ++l;
            else
                for (; l < r && nums[l] == nums[m]; ++l);
        }
        return nums[l];
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{1,2}, 1},
            {{1,1,-1,1}, -1},
            {{3,1,1,1,3}, 1},
            {{2,1}, 1},
            {{1}, 1},
            {{1,1}, 1},
            {{1,1,1}, 1},
            {{1,2,3}, 1},
            {{4, 5, 6, 7, 0, 1, 2}, 0},
            {{}, -1}
    };
    for (auto test : tests) {
        auto tmp=s.findMin(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }










