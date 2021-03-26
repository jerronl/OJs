/*
 * 96.partitionlist.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/96
 *     Given a linked list, remove the nth node from the end of list and return its head.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode* partition(ListNode *head, int x) {
        ListNode *l1 = nullptr, *l2 = nullptr, **p1 = &l1, **p2 = &l2;
        for (; head; head = head->next) {
            auto p = head->val < x ? &p1 : &p2;
            **p = head;
            *p = &head->next;
        }
        *p1 = l2;
        *p2 = nullptr;
        return l1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,int>,ListNode>> tests={
            {{{1,4,3,2,5,2},3},{1,2,2,4,3,5}},
            {{{1,4,3,2,5,2},1},{1,4,3,2,5,2}},
            {{{1,4,3,2,5,2},5},{1,4,3,2,2,5}}
    };
    if(s.partition(nullptr,0))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l2=&test.second;
        auto tmp=s.partition(l1,test.first.second);
        if (!assertl(tmp,l2)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













