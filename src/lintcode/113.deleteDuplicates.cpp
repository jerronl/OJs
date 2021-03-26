/*
 * 113.deleteDuplicatesII.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/113
 *     Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode* deleteDuplicates(ListNode *head) {
        ListNode *p1=head,*p2=head?head->next:nullptr,**pp=&head,*next;
        for(auto prev=head?head->val:0;p2;p2=next){
            next=p2->next;
            if(prev==p2->val){
                delete p2;
                delete p1;
                p1=nullptr;
            }else{
                prev=p2->val;
                if((*pp=p1))
                    pp=&p1->next;
                p1=p2;
            }
        }
        *pp=p1;
        return head;
    }
};
int main(){
    Solution s;
    vector<pair<ListNode*,ListNode>> tests={
            {ListNode::buildList({1,1,2}),{2}},
            {ListNode::buildList({1,1,2,3,3,4}),{2,4}},
            {ListNode::buildList({1,1,1,2,2}),{}}
    };
    if(s.deleteDuplicates(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=test.first,*l3=&test.second;
        auto tmp=s.deleteDuplicates(l1);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test.second << tmp<<endl;
            return 0;
        }
        tmp->del();
    }
    cout << "SUCCEED!";
    return 0;
 }