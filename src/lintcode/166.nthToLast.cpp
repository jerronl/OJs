/*
 * 166.nthToLast.cpp
 *
 *  Created on: Mar 10, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/166
 *     Given a linked list, Find the nth to last element of a singly linked list. 
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode* nthToLast(ListNode *head, int n) {
        auto p1=head,p2=p1;
        for(;--n>=0;p2=p2->next);
        for(;p2;p1=p1->next,p2=p2->next);
        return p1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,int>,ListNode>> tests={
            {{{1,2,3,4,5},2},{4,5}},
            {{{5,4,3,2,1},2},{2,1}},
            {{{1,2,3,4,5},1},{5}},
            {{{1,2,3,4,5},5},{1,2,3,4,5}}
    };
    if(s.nthToLast(&tests.front().first.first,0))
            cout << "FAILED!" << endl;
    else    
    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l2=&test.second;
        auto tmp=s.nthToLast(l1,test.first.second);
        if (!assertl(tmp,l2)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













