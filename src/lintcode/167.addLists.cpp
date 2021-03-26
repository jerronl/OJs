/*
 * 165.addLists.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/165
 *     You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        ListNode *h=nullptr,**p=&h;
        for(int c=0,base=10;l1||l2||c;){
            if(l1){
                c+=l1->val;
                l1=l1->next;
            }
            if(l2){
                c+=l2->val;
                l2=l2->next;
            }
            *p=new ListNode(c % base);
            p=&(*p)->next;
            c/=base;
        };
        return h;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,ListNode>,ListNode>> tests={
            {{{7,1,6},{5,9,2}},{2,1,9}},
            {{{5},{5,9,2}},{0,0,3}},
            {{{7,1,6},{5}},{2,2,6}},
            {{{7,1,6},{5,9,8}},{2,1,5,1}}
    };
    if(s.addLists(nullptr,nullptr)||
            !assertl(s.addLists(nullptr, &tests.front().first.first),&tests.front().first.first)||
            !assertl(s.addLists(&tests.front().first.first,nullptr),&tests.front().first.first))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l2=&test.first.second,*l3=&test.second;
        auto tmp=s.addLists(l1,l2);
        if (!assertl(tmp,l3)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
        tmp->del();
    }
    cout << "SUCCEED!";
    return 0;
 }