/*
 * 83.singleNumberII.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/83
 *     Given 3*n + 1 non-negative integer, every numbers occurs triple times except one, find it.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        int res=0,n=sizeof(int)*8,dup=3;
        vector<int> cnt(n,0),tests(n);
        for(int i=0,test=1;i<n;++i,test+=test)
            tests[i]=test;
        for(auto a:A)
            for(int i=0;i<n;++i)
                if(tests[i]&a)
                    ++cnt[i];
        for(int i=0;i<n;++i)
            if(cnt[i]%dup)
                res+=tests[i];
        return res;
    }
};
int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{0,1,1,1},0},
            {{1,1,1,2},2},
            {{1,1,2,3,3,3,2,2,4,1},4},
            {{2,1,2,2}, 1}
    };
    for (auto test : tests) {
        auto tmp=s.singleNumberII(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }