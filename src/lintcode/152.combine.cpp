/*
 * 152.combine.cpp
 *
 *  Created on: Mar 29, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/152
 *     Given two integers n and k. Return all possible combinations of k numbers out of 1, 2, ... , n.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        vector<int> states(k,0);
        vector<vector<int>> results;
        for(int i=0,j;i>=0;)
            if(i>=k){
                results.push_back(states);
                --i;
            }else if((j=++states[i])<=n)
                ++i<k&&(states[i]=j);
            else
                --i;
        return results;
    }
};

int main(){
    Solution s;
    vector<pair<pair<int,int>,vector<vector<int>>>> tests={
        {{1,1},{{1}}},
        {{3,0},{{}}},
        {{3,1},{{1},{2},{3}}},
        {{4,2},{{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}}
    };
    for (auto test : tests) {
        auto tmp=s.combine(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }