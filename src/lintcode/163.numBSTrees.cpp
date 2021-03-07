/*
 * 163.numBSTrees.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/163
 *      Given n, how many structurally unique BSTs (binary search trees) that store values 1...n?
 */
#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n < 0)
            return 0;
        vector<int> cnt(n + 1, 0);
        for (int i = cnt[0] = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                cnt[i] += cnt[j - 1] * cnt[i - j];
        return cnt[n];
    }
};

int main(){
    Solution s;
    vector<pair<int,int>> tests={
        {3,5},
        {0,1},
        {-1,0},
        {10,16796}
    };
    for (auto test : tests) {
        auto tmp=s.numTrees(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }








