/*
 * 139.subarraySumClosest.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/139
 *      Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.
 */
#include "../utils/utils.h"


class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        int n = nums.size(), minsum = INT_MAX;
        vector<pair<int, int>> helper { { 0, -1 } };
        vector<int> res{-1,0};
        for (int i = 0, sum = 0; i < n; ++i)
            helper.push_back({ sum += nums[i], i });

        sort(helper.begin(), helper.end());
        for (int i = 0, sum; i < n; ++i) {
            if (abs(sum = helper[i + 1].first - helper[i].first) < minsum) {
                res = { helper[i + 1].second, helper[i].second };
                minsum = sum;
            }
        }
        if (res[0] > res[1])
            swap(res[0], res[1]);
        return {res[0]+1,res[1]};
    }
};


int main(){
    Solution s;
    vector<pair<vector<int>,vector<int>>> tests={
        {{6,-4,-8,3,1,7},{1,5}},
        {{2147483647},{0,0}},
        {{-3,1,1,-3,5},{0,2}}
    };
    for (auto test : tests) {
        auto tmp = s.subarraySumClosest(test.first);
        int sum1=0,sum2=0;
        for(auto i=tmp[0];i<=tmp[1];++i) sum1+=test.first[i];
        for(auto i=test.second[0];i<=test.second[1];++i) sum2+=test.first[i];
        if (abs(sum1) !=abs( sum2)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }


