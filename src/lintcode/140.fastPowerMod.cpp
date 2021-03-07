/*
 * 140.fastPowerMod.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/140
 *     Calculate the a^n \% b where a, b and n are all 32bit non-negative integers.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (a < 2)
            return a % b;
        int i = log(LLONG_MAX) / log(a);
        if (n <= i)
            return ((long long) powl(a, n)) % b;
        int a1 = fastPower(((unsigned long long) powl(a, i)) % b, b, n / i),
                a2 = ((long long) powl(a, n % i)) % b;
        return ((long long) a1 * a2) % b;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{2,2147483647,2147483647}, 2},
            {{1,1,1}, 0},
            {{33311,123898,4}, 111861},
            {{76281,123898,57}, 84839},
            {{42275,123898,19}, 84839},
            {{17817,123898,228}, 84839},
            {{59783,123898,685}, 41409},
            {{2147483647,1000000007 ,2}, 850618742},
            {{11,123898,12345}, 78433},
            {{32752,32759,32512}, 16287},
            {{134217712, 134217719, 134217472}, 45804854},
            {{3,7,5}, 5},
            {{8,9,9}, 8},
            {{2,3,31}, 2},
            {{100,1000,1000},0}
    };
    for (auto test : tests) {
        auto tmp=s.fastPower(test.first[0],test.first[1],test.first[2]);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













