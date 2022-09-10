/*
 * 102.levelOrder.cpp
 *
 *  Created on: June 30, 2022
 *      Author: jerron
 *      https://leetcode.com/problems/binary-tree-level-order-traversal/
 *     Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 */
#include "../utils/utils.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        for(vector<TreeNode*> parents={root},children;!parents.empty();parents=children){
            result.push_back({});
            children.clear();
            for(auto p:parents)
                if(p){
                result.back().push_back(p->val);
                children.push_back(p->left);
                children.push_back(p->right);
            }
        }
        result.pop_back();
        return result;
    }
};



int main(){
    Solution s;
    vector<pair<TreeNode, vector<vector<int>>>> tests={
        {{3,9,20,INT_MIN,INT_MIN,15,7},{{3},{9,20},{15,7}}},
        {{1},{{1}}},
        {{},{}}
    };
    for (auto test : tests) {
        auto tmp=s.levelOrder(&test.first);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }









