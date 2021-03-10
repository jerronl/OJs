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
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](int l, int r) {
            string lhs = to_string(l), rhs = to_string(r);
            return (lhs + rhs) > (rhs + lhs);
        });
        string res;
        for (auto n : nums)
            res += to_string(n);
        return res.empty() && res[0] == '0' ? "0" : res;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,string>> tests={
            {{25,5,12,97,3,8,79,73,38,88,98,29,84,74,16,2,67,65,41,44,88,75,51,87,95,90,45,40,7,53,5,30,77,5,56,58,41,51,62,88,33,69,81,78,18,63,82,90,21,6,12,92,67,6,81,83,14,6,76,85,79,96,41,44,20,89,59,58,83,58,73,1,41,41,24,55,61,49,10,42,5,1,98,30,91,9,34,5,84,43,73,4,22,11,21,14,1,62,77,41}, "998989796959291909089888888887858484838382818179797877777767574737373696767666656362626159585858565555555535151494544444434241414141414140383433330302925242222121201816141412121111110"},
            {{1, 20, 23, 4, 8}, "8423201"},
            {{4, 6, 65}, "6654"},
            {{0,0,5}, "500"},
            {{0,0}, "0"},
            {{}, "0"}
    };
    for (auto test : tests) {
        auto tmp=s.largestNumber(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













