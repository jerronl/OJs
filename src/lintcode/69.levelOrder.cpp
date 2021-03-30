/*
 * 69.levelOrder.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/69
 *     Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to ri
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> results{};
        queue<TreeNode*> Q{};
        Q.push(root);
        while(!Q.empty()){
            vector<int> result;
            for(auto i=Q.size();i;--i,Q.pop()){
            auto q=Q.front();
            if(q){
                result.push_back(q->val);
                Q.push(q->left);
                Q.push(q->right);
            }}
            results.push_back(result);
        }
        results.pop_back();
        return results;
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,vector<vector<int>>>> tests={
        {{1,2,3,INT_MIN,INT_MIN,4,5},{{1},{2,3},{4,5}}},
        {{1,2,3},{{1},{2,3}}}
    };
    if(s.levelOrder(nullptr)!=vector<vector<int>>{})
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.levelOrder(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }