/*
 * 16.permuteUnique.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/16
 *     Given a list of numbers with duplicate numbers in it. Find all unique permutations.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> results;
        int n=nums.size(),prev;
        sort(nums.begin(),nums.end());
        vector<int> states(n+1,-1),used(n+1,0);
        for(int i=0;i>=0;)
            if(i>=n){
                vector<int> result(n);
                for(int j=0;j<n;++j)
                    result[j]=nums[states[j]];
                results.push_back(result);
                --i;
            }else{
            bool ok=false;
            for(used[states[i]+1]=0,prev=states[i]>-1?nums[states[i]]:nums[0]-1;!ok&&++states[i]<n;)
                ok=!used[states[i]+1]&&prev!=nums[states[i]];
            if(ok){
                used[states[i]+1]=1;
                states[++i]=-1;
            }
            else
                --i;
        }
        return results;
    }
};

int main(){
    Solution s;
    vector<pair<vector<int>,vector<vector<int>>>> tests={
        {{},{{}}},
        {{1},{{1}}},
        {{1,1},{{1,1}}},
        {{1,2},{{1,2},{2,1}}},
        {{1,2,2},{{1,2,2},{2,1,2},{2,2,1}}}
    };
    for (auto test : tests) {
        auto tmp=s.permuteUnique(test.first);
        if(!asserteqv(tmp,test.second)){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
