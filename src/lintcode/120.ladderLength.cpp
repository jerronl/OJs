/*
 * 120.ladderLength.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: jerron
 *      https://www.lintcode.com/problem/120
 *     Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, output the length of the sequence.
 *      */

#include "../utils/utils.h"
class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        unordered_set<string> S[2]{{start},{end}};
        dict.insert(end);
        int cur=0,target=1,result=1;
        if(start!=end)
        for(;++result;cur=1-(target=cur)){
            unordered_set<string> ns;
            for(auto s:S[cur]){
                dict.erase(s);
                for(auto &c:s){
                    auto o=c;
                    for(c='a';c<='z';++c)
                        if(dict.count(s)){
                            if(S[target].count(s))
                                return result;
                            ns.insert(s);
                        }
                    c=o;
                }
            }
            if(ns.empty())
                return -1;
            S[cur]=ns;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<pair<pair<vector<string>,unordered_set<string>>,int>> tests={
        {{{"a","a"},{"a","b","c"}},1},
        {{{"a","c"},{"a","b","c"}},2},
        {{{"a","c"},{"b"}},2},
        {{{"hit","cog"},{"hot","dot","dog","lot","log"}},5}
    };
    for (auto test : tests) {
        auto tmp=s.ladderLength(test.first.first[0],test.first.first[1],test.first.second);
        if(tmp!=test.second){
            cout << "FAILED!" << test << tmp<<endl;
            return 0;
        }
    }
    cout << "SUCCEED!";
    return 0;
 }
