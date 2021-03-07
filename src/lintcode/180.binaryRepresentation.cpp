/*
 * 180.binaryRepresentation.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/180
 *     Given a (decimal - e.g. 3.72) number that is passed in as a string, return the binary representation that is passed in as a string. If the fractional part of the number can not be represented accurately in binary with at most 32 characters, return ERROR.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n) {
        string res;
        int base1 = 10, base2 = 2, state = 0, i = 0;
        long long f = 0, b = 1;
        for (auto c : n) {
            if (c == '+') {
                if (state == 0)
                    state = 1;
                else
                    break;
            } else if (c >= '0' && c <= '9') {
                if (state < 2) {
                    i *= base1;
                    i += c - '0';
                } else {
                    b *= base1;
                    f *= base1;
                    f += c - '0';
                    if (b > LLONG_MAX / base1)
                        break;
                }
            } else if (c == '.') {
                if (state < 2)
                    state = 2;
                else
                    break;
            }
        }
        for (;;) {
            res.insert(0, 1, i % base2 + '0');
            if (!(i /= base2))
                break;
        }
        if (f > 0) {
            res += '.';
            for (i = 0; i < 32 && f > 0; ++i) {
                f *= base2;
                res += f / b + '0';
                f %= b;
            }
            if (f > 0)
                return "ERROR";
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<pair<string,string>> tests={
            {"4096.643554687500000000000","1000000000000.1010010011"},
            {"6.125","110.001"},
            {"3.75","11.11"},
            {"3.72","ERROR"},
            {"3","11"}
    };
    for (auto test : tests) {
        auto tmp=s.binaryRepresentation(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













