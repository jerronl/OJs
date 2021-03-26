/*
 * 98.sortList.cpp
 *
 *  Created on: Mar 24, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/98
 *     Given a sorted linked list, delete all duplicates such that each element appear only once.Sort a linked list in O(n log n) time using constant space complexity.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        function<ListNode*(ListNode*,ListNode*)> qs=[&qs](ListNode* begin, ListNode* end)->ListNode*{
            if(begin==end)
                return begin;
            auto m=begin,*l=&begin,*r=&m->next,p=*r;
            for(auto par=m->val;p!=end;){
                auto n=p->val>par?&r:&l;
                **n=p;
                p=*(*n=&p->next);
            }
            *l=m;
            *r=end;
            begin=qs(begin,m);
            // for(;m!=end&&m->next!=end&&m->val==m->next->val;m=m->next);
            m->next=qs(m->next,end);
            return begin;
        };
        return qs(head,nullptr);
    }
};

int main(){
    Solution s;
    vector<pair<ListNode,ListNode>> tests={
            {{1,1,2},{1,1,2}},
            {{1},{1}},
            {{2,3,1,1,3},{1,1,2,3,3}}
    };
    if(s.sortList(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first,*l3=&test.second;
        auto tmp=s.sortList(l1);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }