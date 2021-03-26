/*
 * 35.reverselist.cpp
 *
 *  Created on: Mar 18, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/35
 *     Reverse a linked list.
 *      */

#include "../utils/utils.h"



class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        ListNode*nh=nullptr;
        while(head){
            auto next=head->next;
            head->next=nh;
            nh=head;
            head=next;
        }
        return nh;
    }
};

int main(){
    Solution s;
    vector<pair<ListNode,ListNode>> tests={
            {{1},{1}},
            {{1,1,2},{2,1,1}},
            {{1,2,3,4},{4,3,2,1}}
    };
    if(s.reverse(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first,*l3=&test.second;
        auto tmp=s.reverse(l1);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
