/*
 * 2.trailingZeros.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/2
 *     Write an algorithm which computes the number of trailing zeros in n factorial.
 */
#include "../utils/utils.h"


class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        long long sum = 0;
        for (; (n /= 5) > 0; sum += n);
        return sum;
    }
};

int main(){
    Solution s;
    vector<pair<long long,long long>> tests={
        {11,2},
        {5,1},
        {0,0},
        {1,0},
        {100,24}
    };
    for (auto test : tests) {
        auto tmp=s.trailingZeros(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









