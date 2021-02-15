/*
 * 57.threeSum.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/57
 *      Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        int n = numbers.size();
        sort(numbers.begin(), numbers.end());
        vector<vector<int>> res;
        for (int left = 0; left < n - 2; ++left)
            if (left < 1 || numbers[left] > numbers[left - 1]) {
                for(int mid = left + 1, right = n - 1;mid < right;) {
                    auto diff = numbers[left] + numbers[mid] + numbers[right];
                    if (!diff) {
                        res.push_back({ numbers[left], numbers[mid], numbers[right] });
                        for (auto cur = numbers[mid];
                                mid < right && numbers[++mid] == cur;);
                    } else if (diff > 0)
                        --right;
                    else
                        ++mid;
                }
            }
        return res;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,vector<vector<int>> >> tests={
        {{1,0,-1,-1,-1,-1,0,1,1,1},{{-1,0,1}}},
        {{2,7,11,15},{}},
        {{-1,0,1,2,-1,-4},{{-1, 0, 1},{-1, -1, 2}}}
    };
    for(auto test:tests){
        auto res=s.threeSum(test.first);
        if (!asserteqv(res,test.second)){
            cout<<"FAILED!"<<test<<res<<endl;
            return 0;
        }
    }
    cout<<"SUCCEED!";
    return 0;
 }




