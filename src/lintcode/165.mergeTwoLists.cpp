/*
 * 165.mergeTwoLists.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/165
 *     Merge two sorted (ascending) linked lists and return it as a new sorted list.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *head = nullptr, **cur = &head;
        while (l1 && l2) {
            auto next = l1->val > l2->val ? &l2 : &l1;
            *cur = *next;
            cur = &(*cur)->next;
            *next = *cur;
        }
        *cur = l1 ? l1 : l2;
        return head;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,ListNode>,ListNode>> tests={
//            {{{1,2,3,4,5},{}},{1,2,3,4,5}},
//            {{{},{1,2,3,4,5}},{1,2,3,4,5}},
            {{{1,3,8,11,15},{2}},{1,2,3,8,11,15}},
            {{{2},{1,3,8,11,15}},{1,2,3,8,11,15}}
    };
    if(s.mergeTwoLists(nullptr,nullptr)||
            !assertl(s.mergeTwoLists(nullptr, &tests.front().first.first),&tests.front().first.first)||
            !assertl(s.mergeTwoLists(&tests.front().first.first,nullptr),&tests.front().first.first))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l2=&test.first.second,*l3=&test.second;
        auto tmp=s.mergeTwoLists(l1,l2);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }