/*
 * 48.majorityNumberIII.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/82
 *     Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
 * 
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, const int k) {
        unordered_map<int,int> M;
        for(auto n:nums){
            auto ite=M.find(n);
            if(ite==M.end()){
                if(M.size()>=k)
                    for(auto ite2=M.begin();ite2!=M.end();)
                        if((--ite2->second)<=0)
                            ite2=M.erase(ite2);
                        else
                            ++ite2;
                if(M.size()<k)
                    M[n]=1;
            }else
                ++ite->second;
        }
        for(auto& m:M)
            m.second=0;
        for(auto n:nums)
            if(M.count(n))
                if(++M[n]>nums.size()/k)
                    return n;
        return -1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
            {{{3,1,2,3,2,3,3,4,4,4},3}, 3},
            {{{1,2,3,4,5,6,7,8,9,3},10},3},
            {{{1,1,2},3}, 1}
    };
    for (auto test : tests) {
        auto tmp=s.majorityNumber(test.first.first,test.first.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }












