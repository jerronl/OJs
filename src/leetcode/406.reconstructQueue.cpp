/*
 * 1647.minDeletions.cpp
 *
 *  Created on: June 29, 2022
 *      Author: jerron
 *      https://leetcode.com/problems/queue-reconstruction-by-height/
 *     reconstruct and return the queue that is represented by the input array people.
 */
#include "../utils/utils.h"


class Solution {
public:
    vector<vector<int>> reconstructQueue(const vector<vector<int>>& people) {
        vector<vector<int>>queue(people.size());
        using cvi=vector<int>;
        auto sort_by_first=[](cvi& v1,cvi& v2){return v1[0]>v2[0]||v1[0]==v2[0]&&v1[1]>v2[1];};
        priority_queue<cvi,vector<cvi>,decltype(sort_by_first)> q(sort_by_first);
        for(auto p:people)
            q.push(p);
        for(int prev=-1,repeat=0,i,j;!q.empty();){
            auto& next=q.top();
            if(next[0]>prev)
                prev=next[i=repeat=0];
            for(j=next[1]-repeat;i<queue.size();++i)
                if(queue[i].empty()&&--j<0){
                    queue[i]=next;
                    repeat=next[1]+1;
                    break;
                }
            q.pop();
        }
        return queue;
    }
};

int main(){
    Solution s;
    vector<pair<const vector<vector<int>>,const vector<vector<int>>>> tests={
        {{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}},{{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}}},
        {{{7,1},{4,4},{7,0},{5,2},{6,1},{5,0}},{{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}}},
        {{{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}, {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}}},
        {{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}},{{3,0},{6,0},{7,0},{5,2},{3,4},{5,3},{6,2},{2,7},{9,0},{1,9}}},
        {{},{}}
    };
    for (auto test : tests) {
        auto tmp=s.reconstructQueue(test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









