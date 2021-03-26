/*
 * 36.reverseBetween.cpp
 *
 *  Created on: Mar 18, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/35
 *     Reverse a linked list from position m to n.
 *      */

#include "../utils/utils.h"



class Solution {
public:
    /**
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reverseBetweend ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        if(head){
        ListNode **h=&head,*cur,*t;
        for(int i=1;i<m;++i)
            (h=&(*h)->next);
        t=*h;
        for(int i=m;i<n &&(cur=t->next);++i){
            t->next=cur->next;
            cur->next=*h;
            *h=cur;
        }}
        return head;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,pair<int,int>>,ListNode>> tests={
            {{{1},{1,1}},{1}},
            {{{1,1,2},{2,3}},{1,2,1}},
            {{{1,1,2},{3,3}},{1,1,2}},
            {{{1,2,3,4},{1,4}},{4,3,2,1}}
    };
    if(s.reverseBetween(nullptr,0,0))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l3=&test.second;
        auto tmp=s.reverseBetween(l1,test.first.second.first,test.first.second.second);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
