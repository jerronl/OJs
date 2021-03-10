/*
 * 116.canJump.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/116
 *     Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        for (int n = A.size(), i = 0, reach = 0; i <= reach; reach= max(reach, A[i] + i), ++i)
            if (reach  >= n - 1)
                return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,bool>> tests={
            {{0},true},
            {{2,3,1,1,4},true},
            {{3,2,1,0,4}, false},
            {{}, true}
    };
    for (auto test : tests) {
        auto tmp=s.canJump(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













