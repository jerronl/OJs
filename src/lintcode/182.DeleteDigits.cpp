/*
 * 182.DeleteDigits.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: jerron
 */




/*
 * 184.largestNumber.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/184
 *     Given a list of non negative integers, arrange them such that they form the largest number.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     */
    string DeleteDigits(string &A, int k) {
        string res;
        for (int i = 0, last = -1, n = A.size() - k; i < n; ++i) {
            for (int j = ++last; j <= k + i; ++j)
                if (A[j] < A[last])
                    last = j;
            if (!res.empty() || A[last] > '0')
                res += A[last];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<pair<pair<string,int>,string>> tests={
            {{"178542",4},"12"},
            {{"90249",2},"24"},
            {{"568431",3},"431"},
            {{"178542",6},""}
    };
    for (auto test : tests) {
        auto tmp=s.DeleteDigits(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













