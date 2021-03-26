/*
 * 99.reorderList.cpp
 *
 *  Created on: Mar 23, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/99
 *     Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 *      */

#include "../utils/utils.h"
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        if(!head)
            return ;
        ListNode * l1=head,*l2=l1,*h2=nullptr;
        for(;l2&&(l2=l2->next);l1=l1->next,l2=l2->next);
        for(l2=l1->next,l1->next=nullptr;l2;l2=l1){
            l1=l2->next;
            l2->next=h2;
            h2=l2;
        }
        for(l1=head,l2=h2;l2;){
            auto p=l2->next;
            l2->next=l1->next;
            l1->next=l2;
            l1=l2->next;
            l2=p;            
        }
    }
};

int main(){
    Solution s;
    vector<pair<ListNode,ListNode>> tests={
            {{1,1,2},{1,2,1}},
            {{1,2,3,4,5},{1,5,2,4,3}},
            {{1,2,3,4},{1,4,2,3}},
            {{1},{1}},
            {{1,2},{1,2}}
    };
    for (auto test : tests) {
        ListNode* l1=&test.first,*l2=&test.second;
        s.reorderList(l1);
        if (!assertl(l1,l2)) {
            cout << "FAILED!" << test << endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }