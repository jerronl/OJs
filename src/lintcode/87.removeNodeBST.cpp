/*
 * 87.removeNode.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/87
 *     Given a root of Binary Search Tree with unique value for each node. Remove the node with given value
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        auto pr=&root;
        while(*pr)
            if((*pr)->val==value){
                auto p=*pr;
                if(p->left){
                    *pr=p->left;
                    if(p->right){
                        auto r=p->left;
                        for(;r->right;r=r->right);
                        r->right=p->right;
                    }
                }else
                    *pr=p->right;
                delete p;
            }else if((*pr)->val>value)
                pr=&(*pr)->left;
            else
                pr=&(*pr)->right;
        return root;
    }
};

int main(){
    Solution s;
    auto t=TreeNode::buildTree({2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5});
    vector<int> tests={1,2,3,4,5};
    if(s.removeNode(nullptr,1))
            cout << "FAILED!" << endl;
    else 

    for (auto test : tests) {
        auto tmp=s.removeNode(t,test);
        if (!TreeNode::isBST( tmp)){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }