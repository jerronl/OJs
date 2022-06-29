/*
 * 127.topSort.cpp
 *
 *  Created on: Apr 7, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/127
 *     Find any topological order for the given graph.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        int n = graph.size();
        vector<DirectedGraphNode*> postOrder(n,nullptr);
        unordered_set<DirectedGraphNode*> visited;
        function<void(DirectedGraphNode*)> dfs=
        [&dfs,&graph,&postOrder,&visited,&n](DirectedGraphNode* node ){
            if(node&&!visited.count(node)){
                visited.insert(node);
                for(auto child:node->neighbors)
                    dfs(child);
                postOrder[--n]=node;
        }};
        for (auto g:graph)
            dfs(g);
        return postOrder;
    }
};

int main(){
    Solution s;
    vector<vector<DirectedGraphNode*>> tests={
        {DirectedGraphNode::makeGraph("0,1,2,3,4#1,3,4#2,1,4#3,4#4")}
    };
    for (auto test : tests) {
        auto tmp=s.topSort(test);
        if (tmp.size()==test.size()){ 
            for(auto i=1u;i<tmp.size();++i)
                for(auto n:tmp[i]->neighbors)
                    for(int j=0;j<i;++j)
                        if(n==tmp[j]){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }}else{
            cout << "FAILED!" << test << tmp<<endl;
            return 0;            
        }
        for(auto t:tmp)
            delete t;
    }
    cout << "SUCCEED!";
    return 0;
 }
