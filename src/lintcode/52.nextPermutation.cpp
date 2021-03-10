/*
 * 52.nextPermutation.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/52
 *     Given a list of integers, which denote a permutation. Find the next permutation in ascending order.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;
        if (i < 0)
            return nums;
        vector<int> elems{ nums.back() };
        for (; i >= 0 && nums[i] >= elems.back(); --i)
            elems.push_back(nums[i]);
        if (i >= 0) {
            for (auto &e : elems)
                if (e > nums[i]) {
                    swap(e, nums[i]);
                    break;
                }
        }
        for (auto e : elems)
            nums[++i] = e;
        return nums;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,vector<int>>> tests={
            {{2,1,1}, {1,1,2}},
            {{0,1,3,2}, {0,2,1,3}},
            {{0},{0}},
            {{2,3,1,1,4},{2,3,1,4,1}},
            {{3,2,1,0}, {0,1,2,3}},
            {{}, {}}
    };
    for (auto test : tests) {
        auto tmp=s.nextPermutation(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }

















