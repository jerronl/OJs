/*
 * 106.sortedListToBST.cpp
 *
 *  Created on: Mar 22, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/106
 *     Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *      */

#include "../utils/utils.h"
class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
        // write your code here
        function<TreeNode*(ListNode*,ListNode*)> ltt=[&ltt](ListNode* head,ListNode* tail)->TreeNode*{
            if(head==tail)
                return nullptr;
            auto l1=head,l2=l1;
            for(;l2!=tail&&l2->next!=tail;l1=l1->next,l2=l2->next->next);
            auto tree=new TreeNode(l1->val);
            tree->left=ltt(head,l1);
            tree->right=ltt(l1->next,tail);
        };
        return ltt(head,nullptr);
    }
};

int main(){
    Solution s;
    vector<ListNode> tests={
            {{1,2,3},
            {2,3,6,7},
            {1}}
    };
    if(s.sortedListToBST(nullptr)){
            cout << "FAILED!"<<endl;
            return 0;
    }
    for (auto test : tests) {
        if (!TreeNode::isBST( s.sortedListToBST(&test)) ){
            cout << "FAILED!" << test << endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
