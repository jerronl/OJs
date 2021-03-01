/*
 * 75.findPeak.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/75
 *     Find a peak element in this array. Return the index of the peak.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int l = 1, r = A.size() - 2;
        while (l < r) {
            auto m = (l + r) / 2;
            if (A[m] > A[m + 1])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{1, 2, 1, 3, 4, 5, 7, 6}, 1},
            {{1,2,1}, 1},
            {{1,2,3,4,1}, 3}
    };
    for (auto test : tests) {
        auto tmp=s.findPeak(test.first);
        if (test.first[tmp]<test.first[tmp+1]||test.first[tmp]<test.first[tmp-1]) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }











