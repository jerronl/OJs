/*
 * 85.insertNode.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/85
 *     Given a binary search tree and a new tree node, insert the node into the tree.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        if(node){
        auto nr=root,*pr=&root;
        while(nr)
            nr=*(pr=nr->val>=node->val?&nr->left:&nr->right);
        *pr=node;
        }
        return root;
    }
};

int main(){
    Solution s;
    vector<pair<pair<TreeNode,TreeNode>,TreeNode>> tests={
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{1}},{2,1,3,1,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,5}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{2}},{2,1,3,INT_MIN,2,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,5}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{3}},{2,1,3,INT_MIN,INT_MIN,3,4,INT_MIN,INT_MIN,INT_MIN,5}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{4}},{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,4,5}},
        {{{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5},{5}},{2,1,3,INT_MIN,INT_MIN,INT_MIN,4,INT_MIN,5,5,INT_MIN}}
    };
    if(s.insertNode(nullptr,nullptr))
            cout << "FAILED!" << endl;
    else if(!assertt(s.insertNode(nullptr,&tests.front().first.second),&tests.front().first.second)||
            !assertt(s.insertNode(&tests.front().first.second,nullptr),&tests.front().first.second))
            cout << "FAILED!" <<tests.front().first.first<< endl;

    for (auto test : tests) {
        auto tmp=s.insertNode(&test.first.first,&test.first.second);
        if (!assertt( tmp,&test.second)){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }