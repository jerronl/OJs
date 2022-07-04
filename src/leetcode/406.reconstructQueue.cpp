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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](vector<int>& v1,vector<int>& v2){return v1[0]<v2[0]||v1[0]==v2[0]&&v1[1]<v2[1];});
        vector<vector<int>>queue(people.size());
        vector<int> empties(people.size());
        int prev=-1,head=0,*cur,*next=&head,steps,pos=0;
        for(auto& e:empties)
            e=++pos;
        for(auto &p:people){
            if(p[0]>prev){
                prev=p[steps=0];
                next=&head;
            }else
                next=cur;
            for(;steps<=p[1];++steps)
                next=&empties[pos=*(cur=next)];
            queue[pos]=p;
            *cur=*next;
        }
        return queue;
    }
};

int main(){
    Solution s;
    vector<pair<vector<vector<int>>,const vector<vector<int>>>> tests={
        {{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}},{{3,0},{6,0},{7,0},{5,2},{3,4},{5,3},{6,2},{2,7},{9,0},{1,9}}},
        {{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}},{{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}}},
        {{{7,1},{4,4},{7,0},{5,2},{6,1},{5,0}},{{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}}},
        {{{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}, {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}}},
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









