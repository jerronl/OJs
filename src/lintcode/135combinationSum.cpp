/*
 * 135.combinationSum.cpp
 *
 *  Created on: Mar 29, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/135
 *     Given a set of candidtate numbers candidates and a target number target. Find all unique combinations in candidates where the numbers sums to target.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>());
        function<vector<vector<int>>(int,int)> cs=[&cs,&candidates](int target,int i)->vector<vector<int>>{
            if(i>=(int)candidates.size()||target<0)
                return {};
            if(target==0)
                return {{}};
            auto R=cs(target,i+1);
            if(i+1>=(int)candidates.size()||candidates[i+1]!=candidates[i]){
                auto R2=cs(target-candidates[i],i);
                for(auto r:R2){
                    r.push_back(candidates[i]);
                    R.push_back(r);
                }
            }
            return R;
        };
        return cs(target,0);
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,vector<vector<int>>>> tests={
        {{{2},4},{{2,2}}},        
        {{{2,3,6,7},7},{{7},{2,2,3}}},
        {{{3,8},13},{}},
        {{{2,3,6,7},7},{{7},{2,2,3}}},
        {{{3,8},0},{{}}},
        {{{1},3},{{1,1,1}}}
    };
    for (auto test : tests) {
        auto tmp=s.combinationSum(test.first.first,test.first.second);
        if (!asserteqv( tmp,test.second)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
