/*
 * 141.sqrt.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/141
 *      Implement int sqrt(int x).
 */
#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        long long res =1+ x / 2,del=res;
        for (;abs(del=res*res-x)>=res*2;res-=del/2/res);
        return del>0?--res:res;
    }
};

int main(){
    Solution s;
    vector<pair<int,int>> tests={
        {999999999,31622},
        {1,1},
        {100,10},
        {99,9},
        {0,0},
        {3,1},
        {4,2}
    };
    for (auto test : tests) {
        auto tmp=s.sqrt(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }






