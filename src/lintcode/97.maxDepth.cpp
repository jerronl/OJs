/*
 * 197.maxDepth.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/197
 *     Given a binary tree, find its maximum depth.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,int>> tests={
        {{1,2,3,INT_MIN,INT_MIN,4,5},3},
        {{1,2,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN},3}
    };
    if(s.maxDepth(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.maxDepth(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }