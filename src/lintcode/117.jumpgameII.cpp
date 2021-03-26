/*
 * 117.jumpgameII.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/117
 *     Given an array of non-negative integers, you are initially positioned at the first index of the array. Your goal is to reach the last index in the minimum number of jumps.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        for(int n=A.size()-1,reach=-1,i=0,res=0,next=0;next>reach;++res){
            if(next>=n)
                return res;
            for (reach=next;i<=reach;++i)
                next=max(next,A[i]+i);
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,int>> tests={
            {{0},0},
            {{9,1,1,2},1},
            {{2,3,1,1,4},2},
            {{2,3,1,1,4,1,1,1},3},
            {{13,52,42,21,58}, 1}
    };
    for (auto test : tests) {
        auto tmp=s.jump(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
