/*
 * 112.deleteDuplicates.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/112
 *     Given a sorted linked list, delete all duplicates such that each element appear only once.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode* deleteDuplicates(ListNode *head) {
        // write your code here
        for (auto cur = head; cur && cur->next;)
            if (cur->next->val == cur->val) {
                auto next = cur->next->next;
                delete cur->next;
                cur->next = next;
            } else
                cur = cur->next;
        return head;
    }
};
int main(){
    Solution s;
    vector<pair<ListNode,ListNode>> tests={
            {{1,1,2},{1,2}},
            {{1,1,2,3,3},{1,2,3}}
    };
    if(s.deleteDuplicates(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first,*l3=&test.second;
        auto tmp=s.deleteDuplicates(l1);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }














