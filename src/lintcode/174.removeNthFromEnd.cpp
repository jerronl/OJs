/*
 * 174.removeNthFromEnd.cpp
 *
 *  Created on: Mar 10, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/174
 *     Given a linked list, remove the nth node from the end of list and return its head.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        ListNode *pend = head, *newh = head, **prev = &newh;
        for (int i = 0; i < n; ++i)  //assume n<=length of the list
            pend = pend->next;
        for (; pend; pend = pend->next, prev = &(*prev)->next);
        if (*prev) {
            auto tmp = *prev;
            *prev = (*prev)->next;
            delete tmp;
        }
        return newh;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,int>,ListNode>> tests={
            {{{1,2,3,4,5},2},{1,2,3,5}},
            {{{5,4,3,2,1},2},{5,4,3,1}},
            {{{1,2,3,4,5},1},{1,2,3,4}},
            {{{1,2,3,4,5},5},{2,3,4,5}},
            {{{},0},{}}
    };
    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l2=&test.second;
        auto tmp=s.removeNthFromEnd(l1,test.first.second);
        if (!assertl(tmp,l2)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }













