/*
 * 82.singleNumber.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/82
 *     Given 2 * n + 1 numbers, every numbers occurs twice except one, find it.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int s = 0;
        for (auto a : A)
            s ^= a;
        return s;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{1,5,8,1,8}, 5},
            {{1,1,2,2,3,4,4}, 3},
            {{0,0,1}, 1},
            {{1}, 1}
    };
    for (auto test : tests) {
        auto tmp=s.singleNumber(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }












