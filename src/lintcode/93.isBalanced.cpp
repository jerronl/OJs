/*
 * 93.isBalanced.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/93
 *     Given a binary tree, determine if it is height-balanced.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        function<int(TreeNode*)> BFS=[&BFS](TreeNode*r)->int{
            if(r){
                auto ld=BFS(r->left),rd=0;
                if(ld<0||(rd=BFS(r->right))<0||abs(ld-rd)>1)
                    return -1;
                return max(ld,rd)+1;
            }
            return 0;
        };
        return BFS(root)>-1;
    }
};

int main(){
    Solution s;
    vector<pair<TreeNode,bool>> tests={
        {{1,2,3,INT_MIN,INT_MIN,4,5},true},
        {{1,2,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN},false}
    };
    if(!s.isBalanced(nullptr))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test.first;
        auto tmp=s.isBalanced(l1);
        if (tmp!=test.second) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }