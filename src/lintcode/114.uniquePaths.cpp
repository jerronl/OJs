/*
 * 114.uniquePaths.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/114
 *     How many possible unique paths are there to move from top-left corner of a m x n grid to its bottowm-right corner by only moving either down or right at any point?
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        long long r1=1;
        for(int i=max(m,n),j=1,s=m+n-1;i<s;++i,++j)
            (r1*=i)/=j;
        
        return r1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<int,int>,int>>tests={
        {{3,80},3240},
        {{1,3},1},
        {{3,1},1},
        {{2,62},62},
        {{3,3},6}
    };
    for (auto test : tests) {
        auto tmp=s.uniquePaths(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }