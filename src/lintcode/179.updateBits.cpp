/*
 * 179.updateBits.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/179
 *     Given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e g , M becomes a substring of N start from i to j)
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask = static_cast<unsigned int>(-1 << (31 - j)) >> (31 - j + i) << i;
        return (n & ~mask) | (m << i);
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{-2,10,24,27}, -83886082},
            {{-11,-789,0,31}, -789},
            {{53822221,-789,0,31}, -789},
            {{342,53822221,0,31}, 53822221},
            {{1024,21,2,6}, 1108},
            {{1024,31,2,6}, 1148}
    };
    for (auto test : tests) {
        auto tmp=s.updateBits(test.first[0],test.first[1],test.first[2],test.first[3]);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }











