/*
 * 58.fourSum.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/58
 *      Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        vector<vector<int>> res;
        int n=numbers.size();
        sort(numbers.begin(),numbers.end());
        for(int i1=0;i1<n-3;){
            for(int i2=i1+1;i2<n-2;){
                for(int diff,i3=i2+1,i4=n-1;i3<i4;){
                    if((diff=numbers[i1]+numbers[i2]+numbers[i3]+numbers[i4]-target)==0)
                        res.push_back({numbers[i1],numbers[i2],numbers[i3],numbers[i4]});
                    if(diff<=0)
                        for(auto cur=numbers[i3];i3<i4&&numbers[++i3]==cur;);
                    if(diff>=0)
                        for(auto cur=numbers[i4];i3<i4&&numbers[--i4]==cur;);
                }
                for(auto cur=numbers[i2];i2<n-2&&numbers[++i2]==cur;);
            }
            for(auto cur=numbers[i1];i1<n-2&&numbers[++i1]==cur;);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,vector<vector<int>> >> tests={
        {{{1,0,-1,-1,-1,-1,0,1,1,1,2},2},{{-1,0,1,2},{-1,1,1,1},{0,0,1,1}}},
        {{{1,0,-1,0,-2,2},-2},{{-2,-1,0,1}}},
        {{{2,7,11,15},3},{}},
        {{{-1,0,1,0,-2,2},0},{{-1, 0, 0, 1},{-2, -1, 1, 2},{-2, 0, 0, 2}}}
    };
    for(auto test:tests){
        auto res=s.fourSum(test.first.first,test.first.second);
        if (!asserteqv(res,test.second)){
            cout<<"FAILED!"<<test<<res<<endl;
            return 0;
        }
    }
    cout<<"SUCCEED!";
    return 0;
 }




