/*
 * 84.singleNumberIII.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/84
 *     Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int x=0,dif=1,r1=0,r2=0;
        for(auto a:A)
            x^=a;
        for(int i=0;i<sizeof(x)*8 && !(x&dif);++i,dif+=dif);
        for(auto a:A)
            *(a&dif?&r1:&r2)^=a;
        auto r3=min(r1,r2);
        return {r3,r1+r2-r3};
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,vector<int>>> tests={
            {{0,1},{0,1}},
            {{1,2,3,3,2,4,1,5},{4,5}},
            {{1,1,2,3,4,4}, {2,3}},
            {{}, {0,0}}
    };
    for (auto test : tests) {
        auto tmp=s.singleNumberIII(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }