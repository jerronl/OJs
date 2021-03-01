/*
 * 60.searchInsert.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/60
 *      Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 */
#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        int l=0,r=A.size();
        while(l<r){
            auto m = (r + l) / 2;
            if (A[m] == target)
                return m;
            if (A[m] < target)
                l=m+1;
            else
                r=m;
        };
        return l;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
            {{{1,3,5,6}, 5}, 2},
            {{{1,3,5,6}, 2}, 1},
            {{{1,3,5,6}, 7}, 4},
            {{{1,3,5,6}, 0}, 0}
    };
    for (auto test : tests) {
        auto tmp=s.searchInsert(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }







