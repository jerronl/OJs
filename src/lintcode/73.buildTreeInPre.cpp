/*
 * 73.buildTree.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/73
 *     Given preorder and inorder traversal of a tree, construct the binary tree.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param preorder: A list of integers that preorder traversal of a tree
     * @param inorder: A list of integers that inorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        stack<TreeNode*>S;
        TreeNode *t=nullptr,**pt=&t;
        for(auto pr=preorder.begin(),in=inorder.begin();pr!=preorder.end();++pr){
            *pt=new TreeNode(*pr);
            if(*pr!=*in){
                S.push(*pt);
                pt=&(*pt)->left;
            }else {
                ++in;
                while(!S.empty()&&S.top()->val==*in){
                    ++in;
                    pt=&S.top();
                    S.pop();
                }
                pt=&(*pt)->right;
            }
        }
        return t;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,vector<int>>,TreeNode>> tests={
        {{{1},{1}},{1}},
        {{{2,1,3},{1,2,3}},{2,1,3}},
        {{{3,1,2,4,5,6},{1,2,3,4,5,6}},{3,1,4,INT_MIN,2,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,6}},
        {{{2,1,4,3,5,6},{1,2,3,4,5,6}},{2,1,4,INT_MIN,INT_MIN,3,5,INT_MIN,INT_MIN,INT_MIN,6}},
        {{{2,1,4,3,6,5},{1,2,3,4,5,6}},{2,1,4,INT_MIN,INT_MIN,3,6,INT_MIN,INT_MIN,5}},
        {{{4,3,2,1,5,6},{1,2,3,4,5,6}},{4,3,5,2,INT_MIN,INT_MIN,6,1}}
    };
    if (s.buildTree({},{}))
        cout << "FAILED!" ;
    for (auto test : tests) {
        auto tmp=s.buildTree(test.first.first,test.first.second);
        if (!assertt( tmp,&test.second)){
            cout << "FAILED!" << test << *tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }