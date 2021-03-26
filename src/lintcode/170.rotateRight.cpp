/*
 * 170.rotateRight.cpp
 *
 *  Created on: Mar 10, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/170
 *     Given a list, rotate the list to the right by k places, where k is non-negative.
 *      */

#include "../utils/utils.h"
class Solution {
public:
    /**
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        if(!head)
            return head;
        ListNode *l1=head, *l2=l1, **p1=nullptr,**p2=nullptr;
        for(;k>0;--k,l2=l2->next?l2->next:head);
        if(l2==head)
            return head;
        for(;l2;l1=*(p1=&l1->next),l2=*(p2=&l2->next));
        if(p1){
            *p1=nullptr;
            *p2=head;
        }
        return l1;
    }
};

int main(){
    Solution s;
    vector<pair<pair<ListNode,int>,ListNode>> tests={
            {{{1},0},{1}},
            {{{1,2,3,4,5},2},{4,5,1,2,3}},
            {{{1,2,3,4,5},8},{3,4,5,1,2}},
            {{{3,2,1},1},{1,3,2}},
            {{{1,2,3,4,5},5},{1,2,3,4,5}},
            {{{1},3},{1}},
            {{{1},1},{1}}
    };
    if(s.rotateRight(nullptr,0)){
            cout << "FAILED!"<<endl;
            return 0;
    }
    for (auto test : tests) {
        ListNode* l1=&test.first.first,*l2=&test.second;
        auto tmp=s.rotateRight(l1,test.first.second);
        if (!assertl(tmp,l2)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
