/*
 * 33.solveNQueens.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/33
 *     Given an integer n, return all distinct solutions to the n-queens puzzle.
 *      */

#include "../utils/utils.h"


class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> states(n+1,-1);
        for(int i=0,j;i>=0;){
            if(i>=n){
                vector<string> result(n);
                for(j=0;j<n;++j)
                    result[j]=string(states[j],'.')+'Q'+string(n-states[j]-1,'.');
                results.push_back(result);
                i=n-2;
            }
            bool ok=false;
            while(!ok&&++states[i]<n){
                for(j=0,ok=true;ok &&j<i;++j)
                    if(states[i]==states[j]||abs(states[i]-states[j])==i-j)
                        ok=false;                
            }
            if(ok)
                states[++i]=-1;
            else
                --i;
        }
        return results;
    }
};

int main(){
    Solution s;
    vector<pair<int,int>> tests={
        {1,1},
        {2,0},
        {3,0},
        {4,2},
        {5,10}
    };
    for (auto test : tests) {
        auto tmp=s.solveNQueens(test.first);
        if ((int)tmp.size()==test.second){
            for(auto r:tmp)
            for(auto i=1u;i<r.size();++i)
                for(int j=0;j<i;++j)
                    if(r[i]==r[j]||abs((int)r[i].find('Q')-(int)r[j].find('Q'))==i-j){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }}else{
            cout << "FAILED!" << test << tmp<<endl;
            return 0;            
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
