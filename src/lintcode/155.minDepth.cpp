/*
 * 155.minDepth.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/155
 *     Given a binary tree, find its minimum depth.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
        return root?(root->left?root->right?
            min(minDepth(root->left),minDepth(root->right)):
            minDepth(root->left):minDepth(root->right))+1:
            0;
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,int>> tests={
        {{1,INT_MIN,2,3},3},
        {{1,2,3,INT_MIN,INT_MIN,4,5},2},
        {{1,2,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN},3}
    };
    if(s.minDepth(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.minDepth(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }