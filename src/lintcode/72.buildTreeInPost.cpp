/*
 * 72.buildTreeInPost.cpp
 *
 *  Created on: Mar 29, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/72
 *     Given inorder and postorder traversal of a tree, construct the binary tree.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param preorder: A list of integers that preorder traversal of a tree
     * @param inorder: A list of integers that inorder traversal of a tree
     * @return: Root of a tree
     */
    using VITE=std::vector<int>::const_iterator;
    TreeNode * buildTree(const vector<int> &inorder,const vector<int> &postorder) { 
        function<TreeNode*(VITE,VITE,VITE,VITE)>BT=[&BT](VITE ib,VITE ie,VITE pb,VITE pe)->TreeNode*{
            if(ib==ie)
                return nullptr;
            auto pos=find(ib,ie,*prev(pe));
            auto root=new TreeNode(*pos);
            root->right=BT(pos+1,ie,pe-(ie-pos),prev(pe));
            root->left=BT(ib,pos,pb,pb+(pos-ib));
            return root;
        };
        return BT(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<int>,vector<int>>,TreeNode>> tests={
        {{{1},{1}},{1}},
        {{{1,2,3},{1,3,2}},{2,1,3}},
        {{{1,2,3,4,5,6},{2,1,6,5,4,3}},{3,1,4,INT_MIN,2,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,6}},
        {{{1,2,3,4,5,6},{1,3,6,5,4,2}},{2,1,4,INT_MIN,INT_MIN,3,5,INT_MIN,INT_MIN,INT_MIN,6}},
        {{{1,2,3,4,5,6},{1,3,5,6,4,2}},{2,1,4,INT_MIN,INT_MIN,3,6,INT_MIN,INT_MIN,5}},
        {{{1,2,3,4,5,6},{1,2,3,6,5,4}},{4,3,5,2,INT_MIN,INT_MIN,6,1}}
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