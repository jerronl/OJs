/*
 * 66.preorderTraversal.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/66
 *     Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to ri
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> result;
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty()){
            auto p=S.top();
            S.pop();
            while(p){
                result.push_back(p->val);
                S.push(p->right);
                p=p->left;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,vector<int>>> tests={
        {{1,2,3,INT_MIN,INT_MIN,4,5},{1,2,3,4,5}},
        {{1,2,3,4,INT_MIN,5,6},{1,2,4,3,5,6}}
    };
    if(s.preorderTraversal(nullptr)!=vector<int>{})
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.preorderTraversal(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }