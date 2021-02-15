/*
 * 59.threeSumClosest.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/59
 *      Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        int n = numbers.size(), mindiff = INT_MAX, diff;
        sort(numbers.begin(), numbers.end());
        for (int left = 0; left < n - 2; ++left)
            if (left < 1 || numbers[left] > numbers[left - 1]) {
                int mid = left + 1, right = n - 1, target2 = target
                        - numbers[left];
                while (mid < right) {
                    diff = numbers[mid] + numbers[right] - target2;
                    if (!diff)
                        return target;
                    else if (diff > 0)
                        --right;
                    else
                        ++mid;
                    if (abs(mindiff) > abs(diff))
                        mindiff = diff;
                }
            }
        return mindiff + target;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
		{{{-2,-3,-4,-5,-100,99,1,4,4,4,5,1,0,-1,2,3,4,5},90},90},
		{{{-2,-3,-4,-5,-100,99,1,4,4,4,5,1,0,-1,2,3,4,5},77},90},
		{{{1,3,4},8},8},
		{{{2,7,11,15},3},20},
		{{{-1,2,1,-4},1},2}
    };
    for(auto test:tests)
        if (!(s.threeSumClosest(test.first.first,test.first.second)==test.second)){
            cout<<"FAILED!"<<test<<s.threeSumClosest(test.first.first,test.first.second)<<endl;
            return 0;
        }

    cout<<"SUCCEED!";
    return 0;
 }




