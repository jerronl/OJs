/*
 * 95.isValidBST.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/95
 *     Given a binary tree, determine if it is a valid binary search tree (BST).
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        function<bool(TreeNode*,TreeNode*,TreeNode*)>isB=[&isB](TreeNode* r, TreeNode* lo, TreeNode* hi)->bool{
        return !r||
            (!lo||r->val>lo->val)&&
            (!hi||r->val<hi->val)&&
            isB(r->left,lo,r)&&isB(r->right,r,hi);            
        };
        return isB(root,nullptr,nullptr);
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,bool>> tests={
        {{1},true},
        {{INT_MIN},true},
        {{INT_MAX},true},
        {{INT_MAX,1},true},
        {{1,1},false},
        {{10,5,INT_MIN,1,100},false},
        {{1,2,3,INT_MIN,INT_MIN,4,5},false},
        {{2,1,4,INT_MIN,INT_MIN,3,5},true}
    };
    if(!s.isValidBST(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.isValidBST(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }