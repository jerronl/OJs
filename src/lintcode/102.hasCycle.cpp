/*
 * 102.hasCycle.cpp
 *
 *  Created on: Mar 22, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/102
 *     Given a linked list, determine if it has a cycle in it.
 *      */

#include "../utils/utils.h"
class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    bool hasCycle(ListNode * head) {
        for(auto p=head;p&&(p=p->next);head=head->next,p=p->next)
            if(p==head)
                return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<ListNode> tests={
            {1,2,3,4},
            {2,3,6,7,8,9}
    };
    if(s.hasCycle(nullptr)){
            cout << "FAILED!"<<endl;
            return 0;
    }
    for (auto test : tests) {
        if ( s.hasCycle(&test) ){
            cout << "FAILED!" << test << endl;
            return 0;
        }
    }
    for (auto test : tests) {
        test.next->next->next=test.next;
        if (! s.hasCycle(&test) ){
            cout << "FAILED!" << test << endl;
            return 0;
        }
    }    
    cout << "SUCCEED!";
    return 0;
 }
