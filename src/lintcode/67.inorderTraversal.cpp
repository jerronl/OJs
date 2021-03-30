/*
 * 67.inorderTraversal.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/67
 *     Given a binary tree, return the inorder traversal of its nodes' values.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> result;
        for(stack<TreeNode*>S;root||!S.empty();S.pop(),root=root->right){
            while(root){
                S.push(root);
                root=root->left;
            }
            root=S.top();
            result.push_back(root->val);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,vector<int>>> tests={
        {{1,2,3,INT_MIN,INT_MIN,4,5},{2,1,4,3,5}},
        {{1,2,3,4,INT_MIN,5,6},{4,2,1,5,3,6}}
    };
    if(s.inorderTraversal(nullptr)!=vector<int>{})
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.inorderTraversal(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }