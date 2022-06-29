/*
 * 153.combinationSum2.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/153
 *     Given a set of candidtate numbers candidates and a target number target. Find all unique combinations in candidates where the numbers sums to target.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end(),greater<int>());
        function<vector<vector<int>>(int,int)>DFS=[&DFS,&num](int target,int i)->vector<vector<int>>{
            if(!target)
                return {{}};
            if(i>=(int)num.size()||target<0)
                return {};
            auto R=DFS(target,i+1);
            for(auto j=i,sum=0;sum+=num[j++];)
                if(j>=(int)num.size()||num[i]!=num[j]){
                    auto R2=DFS(target-sum,j);
                    for(auto r:R2){
                        r.insert(r.end(),j-i,num[i]);
                        R.push_back(r);
                    }
                    break;
                }
            return R;
        };
        return DFS(target,0);
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,vector<vector<int>>>> tests={
        {{{1,1,1,3,3},3},{{1,1,1},{3}}},        
        {{{1,1},1},{{1}}},        
        {{{7,1,2,5,1,6,10},8},{{1,1,6},{1,2,5},{1,7},{2,6}}},        
        {{{2,2},4},{{2,2}}},        
        {{{2},4},{}},        
        {{{2,3,6,7},7},{{7}}},
        {{{3,8},13},{}},
        {{{2,2,3,6,7},7},{{7},{2,2,3}}},
        {{{3,8},0},{{}}},
        {{{1},3},{}}
    };
    for (auto test : tests) {
        auto tmp=s.combinationSum2(test.first.first,test.first.second);
        if (!asserteqv( tmp,test.second)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
