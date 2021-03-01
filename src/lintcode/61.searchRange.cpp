/*
 * 61.searchRange.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: jerron
 */



/*
 * 14.binarySearch.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/14
 *     Given a sorted array of n integers, find the starting and ending position of a given target value.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        int l = 0, r = A.size(), start;
        while (l < r) {
            auto m = (l + r) / 2;
            if (A[m] < target)
                l = m + 1;
            else
                r = m;
        }
        for (start = l, r = A.size(); l < r;) {
            auto m = (l + r) / 2;
            if (A[m] > target)
                r = m;
            else
                l = m + 1;
        }
        if (start < r)
            return {start,r-1};
        else
            return {-1,-1};
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,vector<int>>> tests={
            {{{1, 2, 3, 3, 4, 5, 10}, 3}, {2,3}},
            {{{1,4,4,5,7,7,8,9,9,10}, 1}, {0,0}},
            {{{1, 2, 3, 3, 4, 5, 10}, 6}, {-1,-1}},
            {{{}, 0}, {-1,-1}}
    };
    for (auto test : tests) {
        auto tmp=s.searchRange(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }










