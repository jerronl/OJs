/*
 * 187.canCompleteCircuit.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/187
 *     Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int accum = -1, sum = 0, start = -1, change;
        for (auto i = 0u; i < gas.size(); ++i) {
            sum += change = gas[i] - cost[i];
            if (accum < 0) {
                start = i;
                accum = change;
            } else
                accum += change;
        }
        return sum < 0 ? -1 : start;
    }
};
int main(){
    Solution s;
    vector<pair<pair<vector<int>,vector<int>>,int>> tests={
            {{{1,1,3,1},{2,2,1,1}}, 2},
            {{{1,1,3,1},{2,2,10,1}}, -1},
            {{{},{}}, -1}
    };
    for (auto test : tests) {
        auto tmp=s.canCompleteCircuit(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }














