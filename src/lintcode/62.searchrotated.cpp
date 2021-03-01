/*
 * 62.searchrotated.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/75
 *     Suppose a sorted array is rotated at some pivot unknown to you beforehand. You are given a target value to search. If found in the array return its index, otherwise return -1.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        int l = 0, r = A.size() - 1;
        if (r < 0)
            return -1;
        while (l <= r) {
            auto m = (l + r) / 2;
            if (A[m] == target)
                return m;
            if (A[m] < target) {
                if (A[m] < A[r] && A[r] < target)
                    r = m - 1;
                else
                    l = m + 1;
            } else if (A[m] > A[r] && A[l] > target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
            {{{4,3}, 3}, 1},
            {{{0,1,2,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1}, -9}, 4},
            {{{4, 5, 6, 1, 2, 3}, 2}, 4},
            {{{4, 5, 1, 2, 3}, 5}, 1},
            {{{4, 5, 1, 2, 3}, 1}, 2},
            {{{4, 5, 1, 2, 3}, 0}, -1},
            {{{4, 5, 6, 1, 2, 3}, 1}, 3},
            {{{4, 5, 6, 1, 2, 3}, 3}, 5},
            {{{4, 5, 6, 1, 2, 3}, 4}, 0},
            {{{4, 5, 6, 1, 2, 3}, 0}, -1},
            {{{4, 5, 6, 1, 2, 3}, 7}, -1},
            {{{4, 5, 9, 1, 2, 3}, 7}, -1},
            {{{1,3,5,6}, 5}, 2},
            {{{1,3,5,6}, 2}, -1},
            {{{1,3,5,6}, 7}, -1},
            {{{1,3,5,6}, 0}, -1}
    };
    for (auto test : tests) {
        auto tmp=s.search(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }












