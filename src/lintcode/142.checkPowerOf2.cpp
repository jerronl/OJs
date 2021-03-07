/*
 * 142.checkPowerOf2.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/142
 *      Using O(1) time to check whether an integer n is a power of 2.
 */
#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

int main(){
    Solution s;
    vector<pair<int,int>> tests={
        {4,true},
        {5,false},
        {0,false},
        {1,true},
        {-1,false},
        {-2147483648,false}
    };
    for (auto test : tests) {
        auto tmp=s.checkPowerOf2(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









