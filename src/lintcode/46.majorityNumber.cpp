/*
 * 46.majorityNumber.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/82
 *     Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        int res = 0, cnt = 1;
        for (auto n : nums) {
            if (n == res)
                ++cnt;
            else
                --cnt;
            if (cnt < 1) {
                cnt = 1;
                res = n;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{1, 1, 1, 1, 2, 2, 2}, 1},
            {{1, 1, 1, 2, 2, 2, 2}, 2},
            {{1}, 1},
            {{0}, 0},
            {{1,2,1,2,3,1,1}, 1}
    };
    for (auto test : tests) {
        auto tmp=s.majorityNumber(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }












