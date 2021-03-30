/*
 * 7.serialize.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/7
 *     Design an algorithm and write code to serialize and deserialize a binary tree
 *      */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        return root?string(",")+to_string(root->val)+serialize(root->left)+serialize(root->right):"#";
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(const string &data) {
        stringstream ss(data);
        function<TreeNode*()>ds=[&ds,&ss]()->TreeNode*{
            if(!ss.eof()){
                char delim;
                ss>>delim;
                if(delim==','){
                    int n;
                    ss>>n;
                    auto r=new TreeNode(n);
                    r->left=ds();
                    r->right=ds();
                    return r;
                }
            }
            return nullptr;
        };        
        return ds();
    }
};

int main(){
    Solution s;
    vector<TreeNode> tests={
        {1},
        {2,1,3},
        {3,1,4,INT_MIN,2,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,6},
        {2,1,4,INT_MIN,INT_MIN,3,5,INT_MIN,INT_MIN,INT_MIN,6},
        {2,1,4,INT_MIN,INT_MIN,3,6,INT_MIN,INT_MIN,5},
        {4,3,5,2,INT_MIN,INT_MIN,6,1}
    };
    if(s.deserialize(s.serialize(nullptr)))
            cout << "FAILED!" << endl;
    else

    for (auto test : tests) {
        TreeNode* l1=&test;
        auto tmp=s.deserialize( s.serialize(l1));
        if (!assertt(l1,tmp)) {
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }