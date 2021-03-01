/*
 * 183.woodCut.cpp
 *
 *  Created on: Feb 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/183
 *     Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        long long l = 1, r = 0,m, s = 0;
        for (auto len : L) {
            s += len;
            r = max((long long)len, r);
        }
        if (s < k)
            return 0;
        r = min(r, s / k);
        while (l <= r) {
            m = (l + r) / 2, s = 0;
            for (auto len : L) {
                s += len / m;
            }
            if (s >= k)
                l = m + 1;
            else
                r = m - 1;
        }
        return l - 1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
            {{{2147483644,2147483645,2147483646,2147483647}, 4}, 2147483644},
            {{{4, 5, 6,7}, 4}, 4},
            {{{232, 124, 456}, 7}, 114},
            {{{1, 2, 3}, 7}, 0},
            {{{4, 5, 6}, 1}, 6},
            {{{4, 5, 6}, 15}, 1},
            {{{}, 5}, 0}
    };
    for (auto test : tests) {
        auto tmp=s.woodCut(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }












