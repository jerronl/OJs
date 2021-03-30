/*
 * 11.searchRange.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/11
 *     Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to ri
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        vector<int> result;
        function<void(TreeNode*)> search=[&search,&result,k1,k2](TreeNode* r){
            if(r){
                if(r->val>k1)
                    search(r->left);
                if(r->val>=k1 && r->val<=k2)
                    result.push_back(r->val);
                if(r->val<k2)
                    search(r->right);
            }
        };
        search(root);
        return result;
    }
};

int main(){
    Solution s;
    vector<pair<pair<TreeNode,pair<int,int>>,vector<int>>> tests={
        {{{5},{6,10}},{}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{0,1}},{1}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{0,3}},{1,2,3}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{2,4}},{2,3,4}}
    };
    if(s.searchRange(nullptr,0,100)!=vector<int>{})
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first.first;
        auto tmp=s.searchRange(l1,test.first.second.first,test.first.second.second);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }