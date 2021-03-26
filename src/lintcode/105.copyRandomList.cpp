/*
 * 105.copyRandomList.cpp
 *
 *  Created on: Mar 22, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/106
 *     A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. Return a deep copy of the list.
 *      */

#include "../utils/utils.h"
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
        for(auto n=head, p=n;p;p=n->next){
            n=new RandomListNode(p->label);
            n->next=p->next;
            p->next=n;       
        }
        for(auto p=head;p;p=p->next->next)
            if(p->random)
                p->next->random=p->random->next;
        auto nh=head,*p=&nh;
        while(head){
            *p=head->next;            
            head=head->next=*(p=&(*p)->next);
        }   
        return nh;
    }
};

int main(){
    Solution s;
    vector< pair< vector<int>,
			 vector<int>>> tests={
            {{1,2,3},{2,3,1}},
            {{1,2,3},{3,2,1}},
            {{1},{0}}
    };
    for (auto test : tests) {
        auto t=RandomListNode(test);
        auto tmp=s.copyRandomList(&t);
        if (!assertr(tmp,&t )){
            cout << "FAILED!" << *tmp<<','<<t << endl;
            return 0;
        }
        tmp->del();
    }
    cout << "SUCCEED!";
    return 0;
 }
