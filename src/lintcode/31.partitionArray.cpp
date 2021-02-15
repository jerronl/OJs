/*
 * 31.partitionArray.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/31
 *      Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums")
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        auto less=0u,greater=0u;
        for(;less<nums.size();++less)
            if(nums[less]<k)
                swap(nums[greater++],nums[less]);
        return greater;
    }
    int partitionArray2(vector<int> &nums, int k) {
        if(!nums.empty())
        for(int l=0,r=nums.size()-1;;){
            for(;nums[l]<k;++l);
            for(;nums[r]>=k;--r);
            if(l<r)
                swap(nums[l++],nums[r--]);
            else
                return l;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,int>,int>> tests={
        {{{3,2,2,1},2},1},
        {{{},9},0}
    };
    for(auto test:tests){
        auto tmp=test.first.first;
        auto res=s.partitionArray(tmp,test.first.second);
        if (res!=test.second){
            cout<<"FAILED!"<<test<<res<<endl;
            return 0;
        }
        for(auto i=0;i<res;++i)
            if(tmp[i]>=test.first.second){
                cout<<"FAILED!"<<test<<res<<endl;
                return 0;
            }
    }
    cout<<"SUCCEED!";
    return 0;
 }




