/*
 * 181.bitSwapRequired.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/181
 *      Determine the number of bits required to flip if you want to convert integer n to integer m.
 */
#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        auto c = a ^ b;
        c = ((c & 0xaaaaaaaa) >> 1) + (c & 0x55555555);
        c = ((c & 0xcccccccc) >> 2) + (c & 0x33333333);
        c = ((c & 0xf0f0f0f0) >> 4) + (c & 0x0f0f0f0f);
        c = ((c & 0xff00ff00) >> 8) + (c & 0x00ff00ff);
        c = ((c & 0xffff0000) >> 16) +(c & 0x0000ffff);
        return c;
    }
};

int main(){
    Solution s;
    vector<pair<pair<int,int>,int>> tests={
        {{31,14},2},
        {{1,-1},31},
        {{1,7},2}
    };
    for (auto test : tests) {
        auto tmp=s.bitSwapRequired(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }






